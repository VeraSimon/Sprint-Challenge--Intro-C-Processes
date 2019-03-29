#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    char *path;
    // Set up that directory pointer
    DIR *dir;
    struct dirent *ent;

    // Parse command line
    // argv argument 0 is the app name itself
    if (argc > 1)
    {
        path = argv[1];
    }
    else
    {
        path = ".";
    }

    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Invalid directory: '%s'\n", argv[1]);
        exit(1);
    }

    // Repeatly read and print entries
    while ((ent = readdir(dir)) != NULL)
    {
        char *path2file = strdup(path);
        strcat(path2file, "/");
        strcat(path2file, ent->d_name);
        struct stat buf;

        if (stat(path2file, &buf) < 0)
        {
            printf("File stat failed for %s\n", path);
            exit(1);
        };
        printf("%ld\t%s\n ", buf.st_size, ent->d_name);
    }

    // Close directory
    closedir(dir);

    return 0;
}
