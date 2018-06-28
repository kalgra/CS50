#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

 int main(int argc, string argv[])
 {
    // check for 2 arguments only
    if (argc != 2)
    {
        printf("Invalid arguments\n");
        return 1;
    }

    // use isalpha in loop to check if argument is all alpha char (no punct)
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key word cannot contain special chars\n");
            return 1;
        }
    }

    // prompt user for plaintext string
    string plaintext = get_string("plaintext :");
    int j = 0;

    // loop through the plaintext string. If not a letter then print as is
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // keep looping through the key word continously
        j = j % strlen(argv[1]);

        // check if the char is alpha
        if (isalpha(plaintext[i]))
        {
            // anticiapate all upper and lower case combinations
            if (islower(plaintext[i]) && islower(argv[1][j]))
                printf("%c", (((plaintext[i] - 97) + (argv[1][j] - 97)) % 26) + 97);
            else if (isupper(plaintext[i]) && islower(argv[1][j]))
                printf("%c", (((plaintext[i] - 65) + (argv[1][j] - 97)) % 26) + 65);
            else if (islower(plaintext[i]) && isupper(argv[1][j]))
                printf("%c", (((plaintext[i] - 97) + (argv[1][j] - 65)) % 26) + 97);
            else if (isupper(plaintext[i]) && isupper(argv[1][j]))
                printf("%c", (((plaintext[i] - 65) + (argv[1][j] - 65)) % 26) + 65);
            j++;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
 }