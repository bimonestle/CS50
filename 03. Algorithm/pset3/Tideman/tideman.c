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


int main(int argc, char* argv[]) {
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: ./tideman [candidate ...]\n");
        return 1;
    }
    return 0;
}