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

    // set key
    int key = atoi(argv[1]);

    // check if the integer is non-negative
    if (key < 0)
    {
        printf("Must be a positive number\n");
        return 1;
    }
    else
    {
        // prompt user for a code to encrypt
        string code = get_string("plaintext: ");

        for (int i = 0, n = strlen(code); i < n; i++)
            {
                //check if the letter is uppercase or lowercase then convert
                if islower(code[i])
                    printf("%c", (((code[i] + key) - 97) % 26) + 97);
                else if isupper(code[i])
                    printf("%c", (((code[i] + key) - 65) % 26) + 65);
                //if neither then just print as is
                else
                    printf("%c", code[i]);
            }
            printf("\n");
    }
 }