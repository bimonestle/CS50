#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name & vote count
typedef struct {
    char *name;
    int votes;
}
candidate;

// Array of candidates
// Determine the size of a candidate arrays
candidate candidates[MAX];

// Number of candidates
int candidate_count;

int argCheck(char* args[], int argc);
int NoV();
bool Vote(char *name);
void printWinner(void);

int main(int argc, char* argv[]) {
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate ...]\n");
        printf("Please enter candidate's name\n");
        return 1;
    }

    // Populate array of candidates and assigns it with initial value;
    // Candidate.name = "Their Name"
    // Candidate.votes = 0
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("The maximum number of candidates is %i", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    
    int voters_count = NoV();

    // Loop over all voters
    for (int i = 0; i < voters_count; i++)
    {
        char *name;
        int len = 1;
        name = (char*) malloc(sizeof(char*) * len);
        printf("I vote: ");
        scanf("%s", name);

        Vote(name);
    }
    printWinner();
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

// Vote for a candidate.
// It takes a char* as an argument
bool Vote(char *name) {
    // Counter for candidate's name validity
    int validCount;

    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            candidates[j].votes++;
            validCount++;
        }
        else
        {
            printf("Invalid candidate's name\n");
        }
    }
    if (validCount != 0)
    {
        return true;
    }
    return false;
}

// Find candidates who have the largest vote.
// Find the maximum in arr[] of size n
int largestVote(candidate candidates[], int size) {
    int i;

    // Initialize the maximum element
    int max = candidates[0].votes;

    // Traverse array elements from second and
    // compare every element with current max
    for (int i = 1; i < size; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
        }
    }
    return max;
}

// Print the candidate's name who has the most votes.
void printWinner(void) {
    int n = sizeof(candidates)/sizeof(candidates[0]);
    int max = largestVote(candidates, n);
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("The winner is %s. With total votes of %i\n", candidates[i].name, candidates[i].votes);
        }   
    }
}