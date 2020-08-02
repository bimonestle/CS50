#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countArgv(int count, char *arg[]);
int readKey(char *arg[]);
int valKey(char *arg[]);
int getSentence(char *arg[]);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int valid = valKey(&argv[1]);
        if (valid > 0)
        {
            printf("Success\n");
            getSentence(&argv[1]);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar {int key}\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar {int key}\n");
        return 1;
    }
}

int countArgv(int count, char *arg[]) {
    int valid = valKey(arg);
    
    if (count == 2 && valid > 0)
    {
        printf("Success\n");
        getSentence(&arg[0]);
        return 1;
    }
    else
    {
        printf("Usage: ./caesar {int key}\n");
        return 0;
    }
}

int readKey(char *arg[]) {
    printf("The key is %s\n", *arg);
    valKey(arg);
    return 1;
}

// Chech if the argument contains letter. Return 1 if contains no letter
int valKey(char *arg[]) {
    int length = strlen(*arg);
    int result = 0;
    // printf("ini: %s, %i\n", *arg,length);

    for (int i = 0; i < length; i++)
    {
        int digit = isdigit(arg[0][i]);
        if (digit < 1)
        {
            // printf("Usage: ./caesar {int key}\n");
            return digit;
            break;
        }
    }
    return 1;
}

// Get the entered text
int getSentence(char *key[]) {
    printf("This is %i\n", atoi(*key));
    char* buffer;
    size_t buffsize = 32;
    size_t characters;
    char* result;
    int tempChar;
    char test;
    char* apa;

    buffer = (char *) malloc(buffsize * sizeof(char));
    result = (char *) malloc(buffsize * sizeof(char));
    apa = (char *) malloc(buffsize * sizeof(char));
    if (buffer == NULL)
    {
        perror("Unable to locate buffer");
    }
    printf("Plain Text: ");
    characters = getline(&buffer, &buffsize, stdin);
    printf("%zu characters were read.\n", characters);
    int length = strlen(buffer) - 1;
    for (int i = 0; i < length; i++)
    {
        if ((int)buffer[i] > 64 && (int)buffer[i] < 91)
        {
            tempChar = ((int)buffer[i] + atoi(*key) - 64) % 26;
            printf("%i", tempChar);
            if (tempChar == 0)
            {
                test = tempChar;
                snprintf(result, *buffer, "%c", test + 90); // convert int to string
                printf("%s", result);
            }
            else
            {
                test = tempChar;
                snprintf(result, *buffer, "%c", test + 64); // convert int to string
                printf("%s", result);
            }
            // test = tempChar;
        }
        else if ((int)buffer[i] > 96 && (int)buffer[i] < 123)
        {
            tempChar = ((int)buffer[i] + atoi(*key) - 96) % 26;
            printf("%i", tempChar);
            if (tempChar == 0)
            {
                test = tempChar;
                snprintf(result, *buffer, "%c", test + 122); // convert int to string
                printf("%s", result);
            }
            else
            {
                test = tempChar;
                snprintf(result, *buffer, "%c", test + 96); // convert int to string
                printf("%s", result);
            }
        }
        else
        {
            snprintf(result, *buffer, "%c", buffer[i]); // convert int to string
            printf("%s", result);
        }
        
        strcat(apa, result);
    }
    printf("\nCipher Text: %s", apa);
    
    return 1;
}