#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float cash;
    int remainder;                  // track cash value
    int counter;

    //Prompt user for ammount of change, only positive float values are valid
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash <= 0);

    //convert decimal to int (dollars to cents)
    remainder = cash * 100;

    //count the number of coins returned
    counter = 0;

    //no of quarters
    while ( remainder >= 25 )
    {
           remainder = remainder - 25;
           counter += 1;
    }

    //no of dimes
    while ( remainder >= 10 )
    {
           remainder = remainder - 10;
           counter += 1;
    }

    // no of nickles
    while ( remainder >= 5 )
    {
           remainder = remainder - 5;
           counter += 1;
    }

    printf("%d\n", counter + remainder);  //no need to loop for pennies so just add what remains in n

}