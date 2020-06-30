#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getSentence(void);
int wordsCount(char *sentence, int charLength);
int sentenceCount(char *sentence, int charLength);
int charCount(char *sentence, int charLength);
int nonAlphCount(char *sentence, int charLength);
int alphCount(char *sentence, int charLength);
float colemanIdx(int L, int S);
float colemanL(char *sentence, int charLength);
float colemanS(char *sentence, int charLength);

int main (void) {
    getSentence();
}

int getSentence(void) {
    char *buffer;
    size_t buffsize = 32;
    size_t characters;

    buffer = (char *) malloc(buffsize * sizeof(char));
    
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Enter sentence: ");
    characters = getline(&buffer, &buffsize, stdin);
    printf("%zu characters were read. \n", characters);
    printf("You just entered: %s\n", buffer);

    wordsCount(buffer, characters);
    sentenceCount(buffer, characters);
    charCount(buffer, characters);
    nonAlphCount(buffer, characters);
    alphCount(buffer, characters);

    int L = colemanL(buffer, characters);
    int S = colemanS(buffer, characters);
    colemanIdx(L, S);
    return 0;
}

float colemanIdx(int L, int S) {
    float index = 0.0588 * L - 0.296 * S - 15.8;
    float result =  round(index);
    printf("The Coleman-Liu Index is %f\n", result);
    if (result < 1)
    {
        printf("Before Grade 1\n");
    } else if(result >= 1 && result < 16)
    {
        printf("Grade %.0f\n", result);
    }
    else
    {
        printf("It's grade 16+\n");
    }
    return result;
}

float colemanL(char *sentence, int charLength) {
    float L = (float)alphCount(sentence, charLength) / (float)wordsCount(sentence, charLength) * 100;
    return L;
}

float colemanS(char *sentence, int charLength) {
    float S = (float)sentenceCount(sentence, charLength) / (float)wordsCount(sentence, charLength) * 100;
    return S;
}

int spaceCount(char *sentence, int charLength) {
    int count = 0;
    for (int i = 0; i < charLength; i++)
    {
        if (sentence[i] == ' ' )
        {
            count++;
        }
    }
    return count;
}

int nonAlphCount(char *sentence, int charLength) {
    int count = 0;
    for (int i = 0; i < charLength; i++)
    {
        if (sentence[i] < 65 || sentence[i] > 122)
        {
            count++;
        }
    }
    printf("Non letters count: %i\n", count - 1);
    return count - 1;
}

int alphCount(char *sentence, int charLength) {
    int count = 0;
    for (int i = 0; i < charLength; i++)
    {
        if (sentence[i] > 64 && sentence[i] < 123)
        {
            count++;
        }
    }
    printf("Letters count: %i\n", count);
    return count;
}

int charCount(char *sentence, int charLength) {
    int counts = charLength - 1;
    printf("Characters counted: %i\n", counts);
    return counts;
}

int wordsCount(char *sentence, int charLength) {
    int result = spaceCount(sentence, charLength) + 1;
    printf("Words count: %i\n", result);
    return result;
}

int sentenceCount(char *sentence, int charLength) {
    int count = 0;
    for (int i = 0; i < charLength; i++)
    {
        if (sentence[i] == '.' || sentence[i] == '?' || sentence[i] == '!')
        {
            count++;
        } 
    }
    printf("Sentence count: %i\n", count);
    return count;
}