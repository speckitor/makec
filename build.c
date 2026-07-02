#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>

void try_rebuild(char **argv)
{
    struct stat exe_info;
    struct stat src_info;

    lstat("./build", &exe_info);
    lstat("./build.c", &src_info);

    if (exe_info.st_ctime < src_info.st_ctime) {
        char *cmd = "gcc build.c -o build";
        printf("%s\n", cmd);
        system(cmd);
        execv("./build", argv);
    }
}

int main(int argc, char **argv)
{
    try_rebuild(argv);

    char *cmd = "gcc main.c -o main";
    printf("%s\n", cmd);
    system(cmd);
    return 0;
}
