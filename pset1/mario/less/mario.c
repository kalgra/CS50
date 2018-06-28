#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    //Get height from user
    do
    {
        height = get_int("Height: ");
    }
    //Height can only be positive numbers from 0-23
    while (height < 0 || height > 23);

    for (int r = height - 1; r >= 0; r--)
        {
            for (int s = 0; s < r; s++)
            {
                printf(" ");
            }
             for (int h = 0; h < height - r + 1; h++)
            {
                printf("#");
            }

        printf("\n");
        }

}