/***********************************************************
Name: Tomas Vasquez 
Assignment: 05
Purpose:  Binary Search Tree that takes in a set of numbers and puts them in their respected order.
Notes:  This program doesnt take user input or a data file. 
***********************************************************/
#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>

#include <iostream>
#include <string>
#include "data.h"
using std::string;

class BinTree{
    public:
        BinTree();
        ~BinTree();

        bool isEmpty();
        int getCount();
        bool getRootData(Data*);

        void clear();               
        bool addNode(int, string);
        bool removeNode(int);        
        bool getNode(Data*, int);
        bool contains (int);         
        int getHeight();             

        //print functions from class
        void displayPreOrder();      
        void displayPostOrder();     
        void displayInOrder();       

        void displayTree();
        void test(DataNode *);

    private: 
        DataNode *root;
        int count;

        void clear(DataNode*);               
        bool addNode(DataNode*, DataNode*);
        DataNode* removeNode(int, DataNode*);     
        bool getNode(Data*, int, DataNode*);
        bool contains (int, DataNode*);          
        int getHeight(DataNode*);                

         //Display functions
        void displayPreOrder(DataNode*);     
        void displayPostOrder(DataNode*);   
        void displayInOrder(DataNode*);      
        DataNode* minValueNode(DataNode*);
        int max (int, int);

        void displayTree(DataNode*);
        DataNode* newNode(int, string);
};




#endif /* HEADER_H */