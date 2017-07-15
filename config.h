namespace config
{
    // ADDITIONAL VARS INFO
    char *env_var_addition_path = ";C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\bin\\HostX64\\x64;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\VC\\VCPackages;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TestWindow;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\CommonExtensions\\Microsoft\\TeamFoundation\\Team Explorer;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\MSBuild\\15.0\\bin\\Roslyn;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Team Tools\\Performance Tools;C:\\Program Files (x86)\\Microsoft Visual Studio\\Shared\\Common\\VSPerfCollectionTools\\;C:\\Program Files (x86)\\Microsoft SDKs\\Windows\\v10.0A\\bin\\NETFX 4.6.1 Tools\\;C:\\Program Files (x86)\\Windows Kits\\10\\bin\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\bin\\10.0.14393.0\\x64;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\\\MSBuild\\15.0\\bin;C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\;C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\Tools\\;";

    char *env_var_additional_info[]  = {
        env_var_addition_path
    };

    char *env_var_additional_names[] = {
        "Path"
    };

    // NEW VARS
    char *env_var_new_include = "INCLUDE=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\include;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\ucrt;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\shared;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\um;C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.14393.0\\winrt;";
    char *env_var_new_libpath = "LIBPATH=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\lib\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\UnionMetadata;C:\\Program Files (x86)\\Windows Kits\\10\\References;C:\\Windows\\Microsoft.NET\\Framework64\\v4.0.30319;";
    char *env_var_new_lib                 = "LIB=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\lib\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\lib\\10.0.14393.0\\ucrt\\x64;C:\\Program Files (x86)\\Windows Kits\\10\\lib\\10.0.14393.0\\um\\x64;";
    char *env_var_new_vcinstalldir        = "VSINSTALLDIR=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\;";
    char *env_var_new_vctools_install_dir = "VCToolsInstallDir=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\;";
    char *env_var_new_vctools_redist_dir  = "VCToolsRedistDir=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Redist\\MSVC\\14.10.25017\\;";
    char *env_var_new_vs_version          = "VisualStudioVersion=15.0";
    char *env_var_new_vs_comntools        = "VS150COMNTOOLS=C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\Tools\\";
    char *env_var_new_vs_cmd_arg_app_plat = "VSCMD_ARG_app_plat=Desktop";
    char *env_var_new_vs_cmd_arg_arch     = "VSCMD_ARG_HOST_ARCH=x64";
    char *env_var_new_vs_cmd_arg_tgt_arch = "VSCMD_ARG_TGT_ARCH=x64";
    char *env_var_new_vs_cmd_ver          = "VSCMD_VER=15.0.26430.12";

    char *env_var_new_info[] = {
        env_var_new_include,    
        env_var_new_libpath,
        env_var_new_lib,
        env_var_new_vcinstalldir,
        env_var_new_vctools_install_dir,
        env_var_new_vctools_redist_dir,
        env_var_new_vs_cmd_arg_app_plat,
        env_var_new_vs_cmd_arg_arch,
        env_var_new_vs_cmd_arg_tgt_arch,
        env_var_new_vs_cmd_ver
    };
    
    char *args_debug   = "--debug";
    char *args_release = "--release";
    char *args_clean   = "--clean";

    #define CONFIG_BIN_DIR_VAR "bin"

    // OPTIMIZATION - /EHsc /fp:fast
    // MISC - MTd (static) Zc:inline?
    char *compiler_path            = "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\" CONFIG_BIN_DIR_VAR "\\HostX86\\x64\\cl.exe";
    char *compiler_options_debug   = "/nologo /W3 /Od /RTC1 /MDd /EHsc /Zc:inline /Gm- /MP /Fo:" CONFIG_BIN_DIR_VAR "\\obj\\ /Fd:" CONFIG_BIN_DIR_VAR "\\debug_compile.pdb /Zi /link /INCREMENTAL:NO /PDB:" CONFIG_BIN_DIR_VAR "\\debug.pdb /subsystem:windows /MACHINE:X64 /debug:fastlink /CGTHREADS:4";
    char *compiler_options_release = "/nologo /W3 /O2 /MD /EHsc /Zc:inline /Gm- /MP /Fo:" CONFIG_BIN_DIR_VAR "\\obj\\ /link /INCREMENTAL:NO /subsystem:windows /MACHINE:X64 /debug:none /CGTHREADS:4";
    char *exe_file_prefix          = " /OUT:" CONFIG_BIN_DIR_VAR "\\";
}
