#include <stdio.h>
#include <stdbool.h>

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
char candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

// Global variables
int pairCount;
int candidateCount;

// Function prototypes
bool Vote(int rank, char name, int ranks[]);
char entName();


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
        candidates[i] = *argv[i + 1];
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
    printf("Number of voters: ");
    int votersCount = scanf("%i", &votersCount);
    
    // Query for votes
    for (int i = 0; i < votersCount; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidateCount];

        // Query for each ranks
        for (int j = 0; j < candidateCount; j++)
        {
            printf("Rank %i: ", j + 1);
            char name = entName();

            if (!Vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
            
        }
        
    }
    return 0;
}

// Update ranks. Given a new vote
bool Vote(int rank, char name, int ranks[]) {

    return false;
}

// Enter the name of the candidate
char entName() {
    char *string;
    scanf("%ms", &string);

    return *string;
}

// Update preferences given one voter's ranks
void recordPreferences(int ranks[]) {
    // TODO
    return;
}