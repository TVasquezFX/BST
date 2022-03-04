/***********************************************************
Name: Tomas Vasquez 
Assignment: 05
Purpose:  Binary Search Tree that takes in a set of numbers and puts them in their respected order.
Notes:  This program doesnt take user input or a data file. 
***********************************************************/
#include "bintree.h"
using namespace std;

//Constructor
BinTree::BinTree()
{
    root =NULL;
    count =0;
}

//Destructor
BinTree::~BinTree()
{
    clear();
}

//Function that checks to see if tree is empty
bool BinTree::isEmpty()
{
    bool state = false; 
    if (count==0)
    {
        state = true; 
    } else 
    {
        state = false; 
    }
    return state; 

}

//Function to check the amout of nodes in tree
int BinTree::getCount()
{
    return count; 
}

//If root exists, fill Data struct with root data & return true. If not, fill with -1, an empty string, & return false.
bool BinTree::getRootData(Data* temproot)
{
    bool found = false;
    
    if (root == NULL)
    {
        temproot->id = -1;
        temproot->information = "";
    }else {
        temproot->id = root->data.id;
        temproot->information = root->data.information;
        found = true;
    }
    return found;
}

//Display tree function 
void BinTree:: displayTree()
{
    displayTree(root);
}

//Display tree function that passes in root
void BinTree::displayTree(DataNode *temproot)
{
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    if (isEmpty())
    {
        cout<<"Tree is empty"<<endl;
    }else 
    {
        cout<<"Tree is NOT empty"<<endl;        // new change     
    }
        cout<<"Height: "<<getHeight()<<endl; 
        cout<<endl;
        cout<<"Node count: "<<getCount()<<endl;
        cout<<endl;
        cout<<"Pre-Order Traversal"<<endl;
        displayPreOrder ();
        cout<<endl;
        cout<<"In-Order Traversal"<<endl;
        displayInOrder();
        cout<<endl;
        cout<<"Post-Order Traversal"<<endl;
        displayPostOrder ();
        cout<<endl;
}

//Add Node tree function 
bool BinTree::addNode(int id , string information)
{
    DataNode* node = newNode(id, information);
    return addNode(node, root);
}

//Add Node tree function that passes in root
bool BinTree::addNode(DataNode* node, DataNode* curr)
{
    if(curr ==nullptr)
    {
        root = node;
        count++;
        return true;
    }
    if(curr->data.id==node->data.id) //duplicate
    {
        delete node;
        return false;
    }
    if (node->data.id>curr->data.id)
    {
        if (curr->right== nullptr)
        {
            curr->right =node;
            count ++;
            return true;
        }else 
        {
            return addNode(node, curr->right);
        }
    }
    else
    {
        if (curr->left== nullptr)
        {
            curr->left =node;
            count ++;
            return true;
        }else 
        {
            return addNode(node, curr->left);
        }
    }
    
}

// A utility helper function to create a new BST node
DataNode* BinTree::newNode(int id , string information)  
{
    DataNode* node = new DataNode;
    node->data.id = id;
    node->data.information = information;
    node->left = nullptr;
    node->right = nullptr;
    return node; 
}


// Remove Node function deletes the key and returns the new root 
DataNode* BinTree::removeNode(int id, DataNode *temproot)
{
    if (temproot){

        // If id to be deleted is smaller than the root's id, then it lies in left subtree 
        if (id<temproot->data.id)
        {
            temproot->left = removeNode(id, temproot->left);
        }
        // If id to be deleted is greater than the root's id, then it lies in right subtree
        else if (id>temproot->data.id)
        {
            temproot->right = removeNode(id, temproot->right);
        }
        else {
            DataNode *temp;
            if(temproot ->left == NULL && temproot ->right == NULL)
            {
                free(temproot);     //remove node
                temproot = NULL;    // then set its location to nullptr
                count--;
            }
            else if (temproot ->left == NULL){
                temp = temproot->right;
                free(temproot);           
                temproot = temp;
                count--;
            } else if (temproot ->right == NULL){
                temp = temproot->left;
                free(temproot);
                temproot = temp;
                count--;
            } else {
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode (temp->data.id, temproot->right);
        }

        }
      }
    return temproot;
}

//Public function that recieves root
bool BinTree::removeNode(int id)
{
    bool location = contains(id);      //location defining variable
    if(!location)
    {
        return false; // not there 
    }
   
    // remove the root
    root = removeNode(id, root);
    return !contains (id);
}

// Given a non-empty BST, return the node with min id value found in tree. 
DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

// Displays nodes according to the "bottom-up" postorder traversal.
void BinTree::displayInOrder (DataNode *temproot)
{
    if(temproot){
        if(temproot->left){
            displayInOrder(temproot->left);
        }
        cout<<temproot->data.id<<" "<<temproot->data.information<<endl;
       if(temproot->right){
           displayInOrder(temproot->right);
       }
       
    }
    return;
}

//Public function that recieves root
void BinTree::displayInOrder()
{
    displayInOrder(root);
}

//data testing for errors
void BinTree::test(DataNode *temproot)
{
    cout << "========================================" << endl;
    if(temproot)
    {
        if(temproot->left)
        {
            cout << "left is: " << temproot->left->data.id << endl;
        }
        else
        {
            cout << "no left" << endl;
        }
        if(temproot->left)
        {
            cout << "right is: " << temproot->right->data.id << endl;
        }
        else
        {
            cout << "no right" << endl;
        }
    }
    else
    {
        cout << "node is NULL" << endl;
    }
    cout << "========================================" << endl;
}

// Function to traverse the tree and check if the given node exists in it
bool BinTree::contains(int id, DataNode *temproot){
    int found = false;

    if(temproot){
        if (id == temproot->data.id){
            found = true;
        } else if (id < temproot->data.id){
            found = contains(id, temproot->left);
        } else {
            found = contains (id, temproot->right);
        }
    }
    return found; 
}

//Public function that recieves node
bool BinTree::contains (int id)
{
    return contains(id,root);
}

//Compute the "maxDepth" of a tree -- the number of  nodes along the longest path from the root node down to the farthest leaf node.
int BinTree::getHeight(DataNode *temproot)
{
    int x = 0, y = 0;

    if(temproot){
        x = getHeight(temproot->left);
        y= getHeight(temproot->right);
    }
    return temproot ? 1 + max(x, y) :0;     /* use the larger one */
}

//Public member of private that recieves the root
int BinTree::getHeight()
{
    return getHeight(root);
}

// Function to check the given id exist or not 
bool BinTree::getNode (Data *temp, int id, DataNode *temproot){
    int found = false; 

    if(temproot){
        if (temproot->data.id ==id){
            temp->id = temproot->data.id;
            temp->information = temproot->data.information;
            found = true;
        }  else if (id < temproot->data.id){
            found = getNode(temp, id, temproot->left);
        }else {
            found = getNode(temp, id, temproot->right);
        }
    }
    return found;
}

//Public function that recieves node
bool BinTree::getNode(Data* temproot, int id )
{
    return getNode(temproot, id, root);
}


// This function traverses tree to delete each  node of the tree
void BinTree::clear(DataNode *temproot){
    if (temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        delete temproot;
        count --;
    }
  
    return;
}

//Public function that recieves node
void BinTree::clear()
{
    clear(root);
    root =nullptr;  //sets root to nullptr
}

// Displays its nodes in preorder
void BinTree::displayPreOrder (DataNode *temproot)
{
    if(temproot){
        cout<<temproot->data.id<<temproot->data.information<<endl;
        if(temproot->left){
            displayPreOrder(temproot->left);
        }
       if(temproot->right){
           displayPreOrder(temproot->right);
       }
    }
    return;
}

// Public member of preorder that recieves the root
void BinTree::displayPreOrder ()
{
    displayPreOrder (root);
}

// Displays its nodes in post order
void BinTree::displayPostOrder (DataNode *temproot)
{
    if(temproot){
        if(temproot->left){
            displayPostOrder(temproot->left);
        }
       if(temproot->right){
           displayPostOrder(temproot->right);
       }
       cout<<temproot->data.id<<temproot->data.information<<endl;
    }
    return;
}

// Public member of post order that recieves the root
void BinTree::displayPostOrder ()
{
    displayPostOrder (root);
}

//Helper function to max height and to minimize long code
int BinTree:: max (int a, int b){
    return ((a > b) ? a:b);
}

