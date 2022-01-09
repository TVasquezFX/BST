/*
 * Put your comment header here
 */

#include "functions.h"

int random_range(int min, int max) {
    //returns a random number between min and max inclusive
    return (rand() % (max - min + 1)) +min;
}

