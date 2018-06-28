// Helper functions for music

#include <cs50.h>

#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int numer;
int denom;
float fract;
int duration(string fraction)
{
    // store index 0 and 2 to integer values 'num' and 'denom' repectively use atoi
    numer = atoi(fraction[0]);
    denom = atoi(fraction[2]);
    // return (numer / denom) / .125
    fract = numer / denom;
    return int fract / .125;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
  //TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0]=='\0')
    {
    return true;
    }
    else
    {
        return false;
    }
}
