namespace config
{
    // ADDITIONAL VARS INFO VS2017
    char *env_var_addition_path_vs2017 = ";C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\bin\\HostX64\\x64;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\VC\\VCPackages;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TestWindow;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TeamFoundation\\Team Explorer;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\MSBuild\\15.0\\bin\\Roslyn;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Team Tools\\Performance Tools;C:\\Program Files (x86)\\Microsoft Visual Studio\\Shared\\Common\\VSPerfCollectionTools\\;C:\\Program Files (x86)\\Microsoft SDKs\\Windows\\v10.0A\\bin\\NETFX 4.6.1 Tools\\;C:\\Program Files (x86)\\Windows Kits\\10\\bin\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.16299.0\\x64;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\\\MSBuild\\15.0\\bin;C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\Tools\\;";

    char *env_var_additional_info_vs2017[]  = {
        env_var_addition_path_vs2017
    };

    char *env_var_additional_names_vs2017[] = {
        "Path"
    };

    const uint32_t env_var_additional_info_count_vs2017 = ARRAYSIZE(env_var_additional_info_vs2017);

    // ADDITIONAL VARS INFO VS2015
    char *env_var_addition_path_vs2015 = ";C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Common7\\IDE\\CommonExtensions\\Microsoft\\TestWindow;C:\\Program Files (x86)\\MSBuild\\14.0\\bin\\amd64;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\BIN\\amd64;C:\\WINDOWS\\Microsoft.NET\\Framework64\\v4.0.30319;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\VCPackages;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Common7\\IDE;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Common7\\Tools;C:\\Program Files (x86)\\HTML Help Workshop;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Team Tools\\Performance Tools\\x64;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Team Tools\\Performance Tools;C:\\Program Files (x86)\\Windows Kits\\10\\bin\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\bin\\x86;C:\\Program Files (x86)\\Microsoft SDKs\\Windows\\v10.0A\\bin\\NETFX 4.6.1 Tools\\x64\\;";

    char *env_var_additional_info_vs2015[]  = {
        env_var_addition_path_vs2015
    };

    char *env_var_additional_names_vs2015[] = {
        "Path"
    };

    const uint32_t env_var_additional_info_count_vs2015 = ARRAYSIZE(env_var_additional_info_vs2015);

    // NEW VARS VS2017
    char *env_var_new_include_vs2017 = "INCLUDE=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\include;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.16299.0\\ucrt;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.16299.0\\shared;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.16299.0\\um;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.16299.0\\winrt;";
    char *env_var_new_libpath_vs2017 = "LIBPATH=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\UnionMetadata;C:\\Program Files (x86)\\Windows Kits\\10\\References;C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319;";
    char *env_var_new_lib_vs2017 = "LIB=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\lib\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\lib\\10.0.16299.0\\ucrt\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\lib\\10.0.16299.0\\um\\x64;";

    char *env_var_new_info_vs2017[] = {
        env_var_new_include_vs2017,    
        env_var_new_libpath_vs2017,
        env_var_new_lib_vs2017
    };

    const uint32_t env_var_new_info_count_vs2017 = ARRAYSIZE(env_var_new_info_vs2017);

    // NEW VARS VS2015
    char *env_var_new_include_vs2015 = "INCLUDE=C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\INCLUDE;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\ATLMFC\\INCLUDE;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\ucrt;C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.6.1\\include\\um;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\shared;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\um;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\winrt;";
    char *env_var_new_libpath_vs2015 = "LIBPATH=C:\\WINDOWS\\Microsoft.NET\\Framework64\\v4.0.30319;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\LIB\\amd64;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\ATLMFC\\LIB\\amd64;C:\\Program Files (x86)\\Windows Kits\\10\\UnionMetadata;C:\\Program Files (x86)\\Windows Kits\\10\\References;\\Microsoft.VCLibs\\14.0\\References\\CommonConfiguration\\neutral;";
    char *env_var_new_lib_vs2015 = "LIB=C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\LIB\\amd64;C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\ATLMFC\\LIB\\amd64;C:\\Program Files (x86)\\Windows Kits\\10\\lib\\10.0.14393.0\\ucrt\\x64;C:\\Program Files (x86)\\Windows Kits\\NETFXSDK\\4.6.1\\lib\\um\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\lib\\10.0.14393.0\\um\\x64;";

    char *env_var_new_info_vs2015[] = {
        env_var_new_include_vs2015,    
        env_var_new_libpath_vs2015,
        env_var_new_lib_vs2015
    };

    const uint32_t env_var_new_info_count_vs2015 = ARRAYSIZE(env_var_new_info_vs2015);
    
    char *args_debug   = "--debug";
    char *args_release = "--release";
    char *args_clean   = "--clean";

    #define CONFIG_BIN_DIR_VAR "bin"

    // OPTIMIZATION - /EHsc /fp:fast
    // MISC - MTd (static) Zc:inline?
    char *compiler_path_vs2015            = "C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\bin\\amd64\\cl.exe";
    char *compiler_path_vs2017            = "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\bin\\HostX86\\x64\\cl.exe";
    char *compiler_options_debug   = "/nologo /W3 /Od /RTC1 /MTd /EHsc /Zc:inline /Gm- /MP /Fo:" CONFIG_BIN_DIR_VAR "\\obj\\ /Fd" CONFIG_BIN_DIR_VAR "\\ /Zi /DDEBUG /link /INCREMENTAL:NO /subsystem:console /MACHINE:X64 /debug:fastlink /CGTHREADS:4";
    //char *compiler_options_debug   = "/nologo /W3 /O2 /MTd /EHsc /Zc:inline /Gm- /MP /Fo:" CONFIG_BIN_DIR_VAR "\\obj\\ /Fd" CONFIG_BIN_DIR_VAR "\\ /Zi /DDEBUG /link /INCREMENTAL:NO /subsystem:console /MACHINE:X64 /debug:fastlink /CGTHREADS:4";
    char *compiler_options_release = "/nologo /W3 /O2 /MT /EHsc /Zc:inline /Gm- /MP /Fo:" CONFIG_BIN_DIR_VAR "\\obj\\ /link /INCREMENTAL:NO /subsystem:console /MACHINE:X64 /debug:none /CGTHREADS:4";
    char *exe_file_prefix          = " /OUT:" CONFIG_BIN_DIR_VAR "\\";
}
