#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

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
        char p2f[sizeof(long long int)];
        struct stat buf;

        snprintf(p2f, sizeof(p2f), "%s\t%s/%s", buf.st_size, path, ent->d_name);
        if (stat(path, &buf) < 0)
        {
            fprintf(2, "File stat failed for %s\n", path);
            exit(1);
        };
        // printf("%lld\t%s\n", stat(*ent, &buf), ent->d_name);
    }

    // Close directory
    closedir(dir);

    return 0;
}