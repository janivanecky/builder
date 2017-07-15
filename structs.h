struct FileList
{
    char     *file_path;
    FileList *next_file;
};

struct CopyFileBatch
{
    FileList *source_files;
    char     *target_directory;

    CopyFileBatch *next_batch;
};

struct BuildSettings
{
    FileList *source_files;
    FileList *pre_hash_files;
    FileList *libraries;
    char *target_exe_name;

    CopyFileBatch *copy_files;
};
