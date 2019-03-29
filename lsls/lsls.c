#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
    // Set up that directory pointer
    DIR *dir;
    struct dirent *ent;

    // Parse command line
    // argv argument 0 is the app name itself
    if (argc > 1)
    {
        // Open directory
        dir = opendir(argv[1]);
        if (dir == NULL)
        {
            printf("Invalid directory: '%s'\n", argv[1]);
            return 1;
        }
    }
    else
    {
        // Open directory
        dir = opendir(".");
    }

    // Repeatly read and print entries
    while ((ent = readdir(dir)) != NULL)
    {
        printf("%s\n", ent->d_name);
    }

    // Close directory
    closedir(dir);
    return 0;
}