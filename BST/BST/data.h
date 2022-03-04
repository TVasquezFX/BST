/***********************************************************
Name: Tomas Vasquez 
Assignment: 05
Purpose:  Binary Search Tree that takes in a set of numbers and puts them in their respected order.
Notes:  This program doesnt take user input or a data file. 
***********************************************************/
#ifndef DATA_H
#define DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
};

struct DataNode {
    Data data;
    DataNode *left, *right;
};

#endif /* DATA_H */
