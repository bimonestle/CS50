#include <stdio.h>
#include <string.h>

int keyLen(char *key[]);
int stringLen(char *string);
int nonAlph(char *string);
int checkRepeatChar(char *string);

int main(int argc, char *argv[]) {
    if (argc == 2)
    {
        printf("succeed %s\n", argv[1]);
        keyLen(&argv[1]);
        nonAlph(argv[1]);
        checkRepeatChar(argv[1]);
    } else if (argc > 2)
    {
        printf("Too many arguments supplied.");
    } else
    {
        printf("One argument expected");
    }

    return 0;
}

int keyLen(char *key[]) {
    // int length = strlen(*key);
    int length = stringLen(*key);
    // printf("Length is %i", length);
    if (length == 26)
    {
        printf("This is well fitted\n");
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
    for (i = 0; string[i] < 65 || string[i] > 122; i++);
    printf("Only alphabet allowed\n");

    return 0;
}

int checkRepeatChar(char *string) {
    int i;
    int count = 0;
    int length = stringLen(string);

    // printf("%s\n", string);
    for (i = 0; i < length; i++)
    {
        printf("%c", string[i]);
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