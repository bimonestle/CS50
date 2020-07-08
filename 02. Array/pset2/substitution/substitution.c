#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int keyLen(char *string);
int stringLen(char *string);
int nonAlph(char *string);
int checkRepeatChar(char *string);
int valKey(char *key);

int main(int argc, char *argv[]) {
    if (argc == 2)
    {
        printf("succeed %s\n", argv[1]);
        valKey(argv[1]);
    } else if (argc > 2)
    {
        printf("Too many arguments supplied\n");
    } else
    {
        printf("One argument expected\n");
    }

    return 0;
}

int keyMapping() {
    

    return 0;
}

int valKey(char *key) {
    int length = keyLen(key);
    int checkAlph = nonAlph(key);
    // printf("ngetes doang ini. %i\n", checkAlph);
    // printf("It is %c", key[1]);
    int repeatChar = checkRepeatChar(key);
    if (length == 26 && repeatChar == 26 && checkAlph < 1)
    {
        printf("This is testing\n");
        char *sentence;
        size_t buffsize = 32;
        size_t characters;

        sentence = (char *)malloc(buffsize * sizeof(char));
        if (sentence == NULL)
        {
            perror("Unable to locate buffer");
            exit(1);
        }

        printf("Plain Text: ");
        characters = getline(&sentence, &buffsize, stdin);
        // printf("Cipher Text: %c\n", sentence[0]);
        printf("bimo %c\n", key[0]);
        printf("Cipher Text: ");
        for (int i = 0; sentence[i] != '\0'; i++)
        {
            // printf("%i", sentence[i]);
            // printf("%i", (int)sentence[i]);
            printf("%c", key[(int)sentence[i] - 65]);
        }
        
    }

    return 0;
}

int keyLen(char *string) {
    // int length = strlen(*key);
    int length = stringLen(string);
    // printf("Length is %i", length);
    if (length == 26)
    {
        printf("This is well fitted\n");
        // nonAlph(string);
        // checkRepeatChar(string);
    }
    else if (length < 26)
    {
        printf("The key is less than 26 characters\n");
    }
    else
    {
        printf("The key is more than 26 characters\n");
    }
    
    return length;
}

int stringLen(char *string) {
    int i;
    for (i = 0; string[i] != '\0'; i++);
    printf("Length is: %i\n", i);
    return i;
}

int nonAlph(char *string) {
    int i;
    int result = 0;
    for (i = 0; string[i] != '\0'; i++){
        if (string[i] < 65 || string[i] > 122)
        {
            printf("Only alphabet allowed!\n");
            result = 1;
        }
    }

    return result;
}

int checkRepeatChar(char *string) {
    int i;
    int count = 0;
    int length = stringLen(string);

    // printf("%s\n", string);
    for (i = 0; i < length; i++)
    {
        // printf("%c", string[i]);
        for (int j = 0; string[j] != '\0'; j++)
        {
            if (string[i] == string[j])
            {
                count++;
            }
        }
    }
    printf("%i\n", count);
    if (count > length)
    {
        printf("Key must not contain repeated characters");
    }
    return count;
}