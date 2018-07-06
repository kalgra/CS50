// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths

int duration(string fraction)
{
    // store index 0 and 2 to integer values 'numer' and 'denom' repectively.
    int numer = (fraction[0] -= 48);
    float denom = (fraction[2] -= 48);
    float fract = numer /  denom;
    return fract / .125;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // note address will always be at 0
    // octave address will always be at string lenth -1
    // Adjust Ascii char to int value. Subtrating 48 will set value to the tru int value.
    int octave = note[strlen(note) - 1];
    octave -= 48;

    // Determine Frequency of note in the given octave
    double freq = 0.0;

     // Calculate the natural frequency based on note, i.e. not sharp or flat. Octave starts with C.
     // base frequency is calculated as note A at the 4th octave.
    switch(note[0])
    {
        case 'C' :
            freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
            break;
        case 'D' :
            freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
            break;
        case 'E' :
            freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
            break;
        case 'F' :
            freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
            break;
        case 'G' :
            freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
            break;
        case 'A' :
            freq = 440.0;
            break;
        case 'B' :
            freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
            break;
        default :
            return 0;
    }

    // Shift by full octaves.
    // If the octave is greater than 4 multiply by 2.
    if(octave > 4)
    {
        for(int i = 0; i < octave - 4; i++)
        {
            freq *= 2.0;
        }
    }
    // If the octave is less than 4 dive by 2.
    else if(octave < 4)
    {
        for(int i = 0; i < 4 - octave; i++)
        {
            freq /= 2.0;
        }
    }

    // Adjust for flat or sharp notes.
    if(note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }
    else if(note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }


    // Round the requecny before returning
    int roundFreq = round(freq);
    return roundFreq;

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
