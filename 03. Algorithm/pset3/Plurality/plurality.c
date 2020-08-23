#include <stdio.h>
#include <string.h>

int argCheck(char* args[], int argc);

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        printf("Please enter candidate's name");
        return 1;
    }
    else
    {
        int check = argCheck(argv, argc);
        if (check > 0)
        {
            printf("Success, %i candidate's name entered\n", argc - 1);
            for (int i = 1; i <= argc - 1; i++)
            {
                printf("Candidate's name entered: '%s'\n", argv[i]);
            }
        }
        else
        {
            printf("There is a duplicate in candidate's name\n");
        }
        return 0;
    }
}

// Check arguments if the name of candidate has duplicate
// return 0 == duplicate, return 1 != duplicate
int argCheck(char* args[], int argc) {
    for (int i = 1; i < argc - 1; i++)
    {
        // printf("%s—i\n", args[i]);
        
        for (int j = i + 1; j < argc; j++)
        {
            // printf("%s—j\n", args[j]);

            // In case of duplicate
            if (strcmp(args[i], args[j]) == 0)
            {
                printf("Reenter distinct candidate's name\n");
                return 0;
            }
        }
    }
    return 1;
}