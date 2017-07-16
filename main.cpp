#include <Windows.h>
#include <stdint.h>
#include <stdio.h>
#include "structs.h"
#include "config.h"
#include "memory.cpp"
#include "string.cpp"
#include "sys_utils.cpp"
#include "file_system.cpp"
#include "parser.cpp"
#include "hasher.cpp"
#include "environment.cpp"

/*
#####################################
TODO
#####################################

- Specify output bin folder
- Add support to switch between console and window subsystem
- Include directories
- Unity build
- More robust copying of files - in case of multiple files with the same name for hashing, add index?
                               - for copys specify target path in sample.build?
- Rename PDB?

*/

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("You need to provide a path to a build file.\n");
        return -1;
    }

    // Default settings
    bool arg_clean = false;
    bool arg_debug = true;

    // Parse args
    for (uint32_t i = 2; i < (uint32_t) argc; ++i)
    {
        char *option = argv[i];
        if (string::equals(option, config::args_debug))
        {
            arg_debug = true;
        }
        else if (string::equals(option, config::args_release))
        {
            arg_debug = false;
        }
        else if (string::equals(option, config::args_clean))
        {
            arg_clean = true;
        }
        else 
        {
            printf("Unrecognized argument %s.", option);
        }
    }
    
    Timer perf_timer = timer::get();
    timer::start(&perf_timer);
    memory::init();

    char *path_to_config_file   = argv[1];
    auto  mem_state_config_file = memory::set(TEMPORARY);

    // Open config file
    File config_file = file_system::read_file(path_to_config_file, TEMPORARY);
    if (config_file.size == 0)
    {
        printf("Incorrect path to build file!\n");
        return -1;
    }

    // Set current dir to that of a config file
    {
        char *directory_path = file_system::get_directory_from_path(path_to_config_file, TEMPORARY);
        if (directory_path)
        {
            SetCurrentDirectoryA(directory_path);
        }
    }

    // In case cleaning option is specified, delete directory with a binary
    if (arg_clean)
    {
        printf("Cleaning bin folder.\n");
        FileList *files = file_system::find_files(CONFIG_BIN_DIR_VAR "/*");
        while(files)
        {
            file_system::delete_file_recursive(files->file_path);
            files = files->next_file;
        }

        file_system::delete_file(CONFIG_BIN_DIR_VAR);
        return 0;
    }

    // Parse config file
    BuildSettings build_settings = parse_config_file(config_file);
    memory::reset(mem_state_config_file, TEMPORARY);
    if(!build_settings.source_files || !build_settings.target_exe_name)
    {
        printf("Need to specify at least full 'build_exe' command - build_exe($exe_name, $source_files)\n");
        return -1;
    }

    // Create necessary directories
    {
        file_system::create_directory(CONFIG_BIN_DIR_VAR);
        file_system::create_directory(CONFIG_BIN_DIR_VAR "\\obj");
    }

    // Pre hash files
    {
        FileList *pre_hash_files = build_settings.pre_hash_files;
        if(pre_hash_files)
        {
            HashDB hash_db = {};
            auto mem_state_date = memory::set(TEMPORARY);
            char *backup_dir_path = sys_utils::get_current_time_and_date_string("'" CONFIG_BIN_DIR_VAR "\\pre_hash_'yy'_'MM'_'dd'_'",
                                                                                    "HH'_'mm'_'ss\\", true, TEMPORARY);
            file_system::create_directory(backup_dir_path);

            while(pre_hash_files)
            {
                hash_file(pre_hash_files->file_path, &hash_db, backup_dir_path);
                pre_hash_files = pre_hash_files->next_file;
            }
            memory::reset(mem_state_date, TEMPORARY);
        }
    }

    // Copy over specified files
    {
        CopyFileBatch *copy_file_batch = build_settings.copy_files;
        while(copy_file_batch)
        {
            FileList *copy_files = copy_file_batch->source_files;
            while(copy_files)
            {
                auto  mem_state = memory::set(TEMPORARY);
                char *copy_file_name = file_system::get_file_name_from_path(copy_files->file_path);
                char *target_copy_file_path = file_system::get_combined_paths(copy_file_batch->target_directory, copy_file_name, TEMPORARY);

                file_system::copy_file(copy_files->file_path, target_copy_file_path);
                memory::reset(mem_state, TEMPORARY);
                
                copy_files = copy_files->next_file;
            }

            copy_file_batch = copy_file_batch->next_batch;
        }
    }

    // Compose compile cmd line
    char *compile_cmd = NULL;
    {
        FileList *source_files = build_settings.source_files;
        uint32_t source_files_paths_length = 1; // Add a space after compiler path
        while(source_files)
        {
            source_files_paths_length += string::length(source_files->file_path) + 1;
            source_files = source_files->next_file;
        }

        FileList *libraries = build_settings.libraries;
        uint32_t libraries_length = 1; // Add a space after compiler path
        while(libraries)
        {
            libraries_length += string::length(libraries->file_path) + 1;
            libraries = libraries->next_file;
        }

        char *compiler_options = arg_debug ? config::compiler_options_debug : config::compiler_options_release;

        uint32_t compiler_path_length    = string::length(config::compiler_path);
        uint32_t compiler_options_length = string::length(compiler_options);
        uint32_t exe_file_name_length    = string::length(build_settings.target_exe_name) + 1; // ntc
        uint32_t exe_file_prefix_length  = string::length(config::exe_file_prefix);
        uint32_t command_line_length     = compiler_path_length + source_files_paths_length + compiler_options_length +
                                           exe_file_prefix_length + exe_file_name_length + libraries_length;
                                           
        compile_cmd = memory::allocate<char>(command_line_length, PERSISTENT);
        char *compile_cmd_ptr = compile_cmd;
        
        memcpy(compile_cmd_ptr, config::compiler_path, compiler_path_length);
        compile_cmd_ptr += compiler_path_length;
        *(compile_cmd_ptr++) = ' ';

        source_files = build_settings.source_files;
        while(source_files)
        {
            uint32_t file_path_length = string::length(source_files->file_path);
            memcpy(compile_cmd_ptr, source_files->file_path, file_path_length);
            compile_cmd_ptr += file_path_length;
            *(compile_cmd_ptr++) = ' ';
            source_files = source_files->next_file;
        }
        memcpy(compile_cmd_ptr, compiler_options, compiler_options_length);
        compile_cmd_ptr += compiler_options_length;
        *(compile_cmd_ptr++) = ' ';
        
        libraries = build_settings.libraries;
        while(libraries)
        {
            uint32_t library_length = string::length(libraries->file_path);
            memcpy(compile_cmd_ptr, libraries->file_path, library_length);
            compile_cmd_ptr += library_length;
            *(compile_cmd_ptr++) = ' ';
            libraries = libraries->next_file;
        }

        memcpy(compile_cmd_ptr, config::exe_file_prefix, exe_file_prefix_length);
        compile_cmd_ptr += exe_file_prefix_length;
        memcpy(compile_cmd_ptr, build_settings.target_exe_name, exe_file_name_length - 1);
        compile_cmd_ptr += exe_file_name_length;
        *(compile_cmd_ptr - 1) = 0;
    }
    
    // Get updated environment settings
    char *new_env_block = NULL;
    {
        char *old_env_block = environment::get_current_env_block();
        new_env_block = environment::update_env_block(old_env_block, config::env_var_additional_info, 
                                                      config::env_var_additional_names, ARRAYSIZE(config::env_var_additional_info), 
                                                      config::env_var_new_info, ARRAYSIZE(config::env_var_new_info), PERSISTENT);
        environment::free_env_block(old_env_block);
    }

    // Create compilation process
    printf("Source files:\n");
    {
        PROCESS_INFORMATION process_info = {};
        STARTUPINFO         startup_info = {};
        startup_info.cb = sizeof(startup_info);

        BOOL return_status = CreateProcessA(NULL, compile_cmd, NULL, NULL, TRUE, NULL, new_env_block, NULL, &startup_info, &process_info);
        if (!return_status)
        {
            char *messageBuffer;
            DWORD  error = GetLastError();
            size_t size  = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                        NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);
            printf("Call to compiler failed! %s\n", messageBuffer);
            return -1;
        }   

        WaitForSingleObject(process_info.hProcess, 5000);
    }

    file_system::delete_file(CONFIG_BIN_DIR_VAR "\\debug_compile.pdb");

    printf("Compilation done! (%fs)\n", timer::end(&perf_timer));
    printf("> %s\n", build_settings.target_exe_name);
    return 0;
}