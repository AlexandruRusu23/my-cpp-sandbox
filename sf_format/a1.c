#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void list_files(char* path, _Bool recursive, char** filteringOptions)
{
    
}

void list_command(int argc, char** argv)
{
    // ./a1 list [recursive] <filtering_options> path=<dir_path>
    int whitelistIndexes[] = {-1, -1};
    _Bool recursive = 0;
    char* path = NULL;
    char** filteringOptions = NULL;
    int filteringOptionsNum = argc - 2;
    for (int i = 2; i < argc; i++)
    {
        // look for recursive and path arguments
        if (strcmp(argv[i], "recursive") == 0)
        {
            whitelistIndexes[0] = i;
            filteringOptionsNum--;
            recursive = 1;
        }
        else if (strstr(argv[i], "path=") != NULL)
        {
            whitelistIndexes[1] = i;
            filteringOptionsNum--;
            int pathLength = strlen(argv[i]) - 5;
            path = malloc(pathLength);
            memcpy(path, (char*)argv[i]+5, pathLength);
        }
    }

    filteringOptions = malloc(filteringOptionsNum * sizeof(char*));
    int filteringOptionsIndex = 0;

    for (int i = 2; i < argc; i++)
    {
        if (!(whitelistIndexes[0] - i) || !(whitelistIndexes[1] - i))
        {
            continue;
        }

        int filterOptionStrLength = strlen(argv[i]);
        filteringOptions[filteringOptionsIndex] = malloc(filterOptionStrLength * sizeof(char*));
        memcpy(filteringOptions[filteringOptionsIndex], argv[i], filterOptionStrLength);
        filteringOptionsIndex++;
    }

    // TO DO
    //list_files();

    for (int i = 0; i < filteringOptionsIndex; i++)
    {
        free(filteringOptions[i]);
    }
    free(filteringOptions);
    free(path);
}

int main(int argc, char** argv)
{
    // we only handle command line passed arguments
    if (argc < 2)
    {
        return 0;
    }

    if(strcmp(argv[1], "variant") == 0)
    {
        printf("70985\n");
        return 0;
    }

    if (strcmp(argv[1], "list") == 0)
    {
        list_command(argc, argv);
        return 0;
    }

    return 0;
}
