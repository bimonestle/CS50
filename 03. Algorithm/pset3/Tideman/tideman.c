#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked over j
bool locked[MAX][MAX];

// each pair has a winner, loser
typedef struct {
    int winner;
    int loser;
}
pair;

// Array of candidates
char* candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

// Global variables
int pairCount;
int candidateCount;

// Function prototypes
bool Vote(int rank, char* name, int ranks[]);
char* entName();
void recordPreferences(int ranks[]);


int main(int argc, char* argv[]) {
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidateCount = argc - 1;
    if (candidateCount > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidateCount; i++)
    {
        candidates[i] = argv[i + 1];
        printf("argv[%i]: %s\n",i+1 , candidates[i]);
    }

    // Clear graph locked in pairs
    for (int i = 0; i < candidateCount; i++)
    {
        for (int j = 0; j < candidateCount; j++)
        {
            locked[i][j] = false;
        }
    }
    
    pairCount = 0;
    int votersCount;
    printf("Number of voters: ");
    scanf("%i", &votersCount);
    
    // QUERY FOR VOTES
    for (int i = 0; i < votersCount; i++)
    {
        printf("VOTERS %i\n", i+1);
        // ranks[i] is voter's ith preference
        int ranks[candidateCount];

        // QUERY FOR EACH RANKS
        // for (int j = 0; j < votersCount; j++)
        for (int j = 0; j < candidateCount; j++)
        {
            printf("Rank %i: ", j + 1);
            char* name = entName();
            printf("name is %s\n", name);

            if (!Vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }   
        }
        recordPreferences(ranks);
        printf("\n");
    }

    return 0;
}

// Update ranks. Given a new vote
bool Vote(int rank, char* name, int ranks[]) {
    // TO DO
    // If name is found among the candidates,
    // update ranks and return true.
    // ranks[i] is the voter's ith preference

    // If no name is found,
    // don't update any ranks and return false.
    printf("Vote for %s\n", name);
    int validCount = 0;
    for (int i = 0; i < candidateCount; i++)
    {
        printf("Candidate %i = %s\n", i+1, candidates[i]);
        if (strcmp(name, candidates[i]) == 0)
        {
            validCount += 1;

            // e.g:
            // Voter 1: ranks[0] == 2. Jon, ranks[1] == Bimo.
            // Voter 2: ranks[0] == 1. Bimo, ranks[1] == Jon.
            // Voter 3: ranks[0] == 2. Jon, ranks[1] == Bimo.
            ranks[rank] = i;
        }
    }
    if (validCount > 0)
    {
        printf("validCount = %i\n", validCount);
        return true;
    }
    return false;
}

// Enter the name of the candidate
char* entName() {
    char* string;
    string = (char*) malloc(sizeof(char) * 1 + 1);
    free(string);
    scanf("%s", string);
    // printf("I vote: %s\n", string);
    return string;
}

// Update preferences given one voter's ranks
void recordPreferences(int ranks[]) {
    // TODO
    return;
}

// Record pairs of candidate where one is preferred over the other
void addPairs(void) {

    // TO DO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sortPairs(void) {
    // TO DO
    return;
}