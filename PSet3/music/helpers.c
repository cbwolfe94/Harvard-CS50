// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    double numerator = fraction[0] - '0';
    double denominator = fraction[2] - '0';

    /*if (denominator % 2 != 0)
    {
        fprintf(stderr, "Not a valid denominator.\n");
        return 1;
    }
    */

    int num_of_eighths = (numerator/denominator)/0.125;
    return num_of_eighths;

    // TODO
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double offset;
    double freq;
    char key = note[0];
    char oct;
    switch(key) {
        case 'C':
            offset = -9;
            break;
        case 'D':
            offset = -7;
            break;
        case 'E':
            offset = -5;
            break;
        case 'F':
            offset = -4;
            break;
        case 'G':
            offset = -2;
            break;
        case 'A':
            offset = 0;
            break;
        case 'B':
            offset = 2;
            break;
    }

    if (strlen(note) == 3)
    {
        oct = note[2];
        char flat_or_sharp = note[1];
        switch (flat_or_sharp) {
            case '#':
                offset++;
                break;
            case 'b':
                offset--;
                break;
        }
    } else
    {
        oct = note[1];
    }
    switch(oct) {
        case '1':
            offset-=36;
            break;
        case '2':
            offset-=24;
            break;
        case '3':
            offset-=12;
            break;
        case '5':
            offset+=12;
            break;
        case '6':
            offset+=24;
            break;
        case '7':
            offset+=36;
            break;
        case '8':
            offset+=48;
            break;
     }
    freq = round(pow(2, offset/12)*440);
    int actual_freq = freq;
    return actual_freq;
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    bool answer = false;
    //string rest = "\0";
    if (s[0] == '\0')
    {
        answer = true;
    } else
    {
        answer = false;
    }
    // TODO
    return answer;
}
