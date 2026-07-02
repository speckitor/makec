#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>

void rebuild_build()
{
    char *cmd = "gcc build.c -o build";
    printf("%s\n", cmd);
    system(cmd);
    execl("./build", NULL);
}

void try_rebuild()
{
    struct stat exe_info;
    struct stat src_info;

    lstat("./build", &exe_info);
    lstat("./build.c", &src_info);

    if (exe_info.st_ctime < src_info.st_ctime)
        rebuild_build();
}

int main(void)
{
    try_rebuild();

    char *cmd = "gcc main.c -o main";
    printf("%s\n", cmd);
    system(cmd);
    return 0;
}
