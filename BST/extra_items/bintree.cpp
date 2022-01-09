#include "bintree.h"
using namespace std;

BinTree::BinTree()
{
    root =NULL;
    count =0;
}

void BinTree:: displayTree()
{
    displayTree(root);
}


void BinTree::displayTree(DataNode *temproot)
{
    if (isEmpty())
    {
        cout<<"Tree is empty"<<endl;
        cout<<"Height: "<<getHeight()<<endl; 
        cout<<endl;
        cout<<"Node count: "<<getCount()<<endl;
        cout<<endl;
    }else 
    {
        cout << "DISPLAY TREE" << endl;
        cout << "==============================================" << endl;
        cout<<"Tree is NOT empty"<<endl;        // new change
            cout<<endl; 
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

                
    }
    // cout<<endl;
    // cout<<"Height"<<endl; 
    // cout<<endl;
    // cout<<"Node count: "<<getCount()<<endl;
    // cout<<endl;
    // cout<<"Pre-Order Traversal"<<endl;
    // displayPreOrder ();
    // cout<<endl;
    // cout<<"In-Order Traversal"<<endl;
    // displayInOrder();
    // cout<<endl;
    // cout<<"Post-Order Traversal"<<endl;
    // displayPostOrder ();
    cout<<endl;
}

bool BinTree::addNode(int id , string information)
{
    DataNode* node = newNode(id, information);
    return addNode(node, root);
}


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

DataNode* BinTree::newNode(int id , string information) //help function 
{
    DataNode* node = new DataNode;
    node->data.id = id;
    node->data.information = information;
    node->left = nullptr;
    node->right = nullptr;
    return node; 
}


DataNode* BinTree::minValueNode(DataNode* node){
    DataNode* current = node;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}


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

void BinTree::displayInOrder()
{
    displayInOrder(root);

}

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

DataNode* BinTree::removeNode(int id, DataNode *temproot)
{
    if (temproot){
        cout << "temp root is " << temproot->data.id << endl;
        if (id<temproot->data.id)
        {
            cout << "move left" << endl;
            temproot->left = removeNode(id, temproot->left);
        }
        else if (id>temproot->data.id)
        {
            cout << "move right" << endl;
            temproot->right = removeNode(id, temproot->right);
        }
        else {
            DataNode *temp;
            if(temproot ->left == NULL && temproot ->right == NULL)
            {
                cout << "delete leaf" << endl;
                //delete temproot;
                free(temproot);
                temproot = NULL;
                count--;
            }
            else if (temproot ->left == NULL){
                temp = temproot->right;
                cout << "temproot right is temp = " << temp->data.id << endl;
                cout << "deleting = " << temproot->data.id << endl;
                // delete temproot;
                free(temproot);
                temproot = temp;
                test(temproot);
                count--;
            } else if (temproot ->right == NULL){
                temp = temproot->left;
                cout << "temproot left is temp = " << temp->data.id << endl;
                cout << "deleting = " << temproot->data.id << endl;
                // delete temproot;
                free(temproot);
                temproot = temp;
                test(temproot);
                count--;
            } else {
                temp = minValueNode(temproot->right);
                cout << "mid temp = " << temp->data.id << endl;
                cout << "deleting = " << temproot->data.id << endl;
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode (temp->data.id, temproot->right);
        }

        }
      }
    return temproot;
}


bool BinTree::removeNode(int id)
{
    bool t = contains(id);
    if(!t)
    {
        return false; // not there 
    }
    cout << "\nattempting to remove " << id << " starting from root id: " << root->data.id << endl;
    root = removeNode(id, root);
    return !contains (id);
}




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

bool BinTree::contains (int id)
{
    return contains(id,root);
}

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

bool BinTree::getNode(Data* temproot, int id )
{
    return getNode(temproot, id, root);
}

void BinTree::clear(DataNode *temproot){
    if (temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        cout << "deleting = " << temproot->data.id << endl;
        delete temproot;
        count --;
    }
  
    return;
}

void BinTree::clear()
{
    clear(root);
    root =nullptr;
}

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

int BinTree::getCount()
{
    return count; 
}

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

void BinTree::displayPreOrder ()
{
    displayPreOrder (root);
}



void BinTree::displayPostOrder (DataNode *temproot)
{
        // if (temproot == NULL)
        // return;

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

void BinTree::displayPostOrder ()
{
    displayPostOrder (root);
}

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


int BinTree::getHeight(DataNode *temproot)
{
    int h1 = 0, hr = 0;
    //cout<<temproot<<endl;

    if(temproot){
        h1 = getHeight(temproot->left);
        hr= getHeight(temproot->right);
    }
    //cout<<temproot<<endl;
    // cout<<"left: "<<h1<<endl;
    // cout<<"right: "<<hr<<endl;
    return temproot ? 1 + max(h1, hr) :0;
}

int BinTree::getHeight()
{
    return getHeight(root);
}

int BinTree:: max (int a, int b){
    return ((a > b) ? a:b);
}

