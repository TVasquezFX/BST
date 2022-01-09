/***********************************************************
Name: Tomas Vasquez 
Assignment: 05
Purpose:  Binary Search Tree that takes in a set of numbers and puts them in their respected order.
Notes:  This program doesnt take user input or a data file. 
***********************************************************/
#include "functions.h"

int random_range(int min, int max) {
    //returns a random number between min and max inclusive
    return (rand() % (max - min + 1)) +min;
}

