#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name & vote count
typedef struct {
    char name;
    int votes;
}
candidate;

int argCheck(char* args[], int argc);
bool Vote();

int main(int argc, char* argv[]) {
    if (argc < 2)
    {
        printf("Please enter candidate's name");
        return 1;
    }
    else
    {
        // Check if argv has duplicate name of candidate
        int check = argCheck(argv, argc);
        if (check > 0)
        {
            printf("Success, %i candidate's name entered\n", argc - 1);
            for (int i = 1; i <= argc - 1; i++)
            {
                printf("Candidate's name entered: '%s'\n", argv[i]);
            }

            // Enter how many voters needed
            Vote();
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

// Enter the number for how many voters needed
// Returns the entered number
int NoV() {
    int voters;
    printf("Number of voters: ");
    scanf("%d", &voters);

    return voters;
}

// Vote the candidate
bool Vote() {
    char *name;
    int len = 1;
    int voters = NoV();
    name = malloc(sizeof(char*) * len);

    // Matching it with the number of voters
    for (int i = 0; i < voters; i++)
    {
        printf("Vote: ");
        scanf("%s", name);
    }
    
    return true;
}