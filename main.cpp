#include <iostream>
#include "btree.h"

using namespace std;

void insertNode(btree * root, int value){
  
    // For the case where the root value is the same as the input value 
    // In BST there needs to be no duplicate values

    if(value == root->getValue())
        return;


    if(value > root->getValue()){

        if(root->getRight() == NULL)
            root->setRight(new btree(value));
        else
            insertNode(root->getRight(), value); 
    }
    else {
    
        if(root->getLeft() == NULL)
            root->setLeft(new btree(value));
        else
            insertNode(root->getLeft(), value);
    }
}

btree * buildTree(istream* in){

    int data = -1;

    btree * root;

    if(in->good()){
    
        (*in)>>data;
        root = new btree(data); 

        while(in->good()){
            
            (*in)>>data;
        
            insertNode(root, data);
        }

    } else {
        cout << "No value from the input" << endl;
    }

    return root;
}

void traverse(btree * root){
    if(root != NULL){
        traverse(root->getLeft());
        cout << root->getValue() << endl;
        traverse(root->getRight());
    }
}

int main(int argc, char* argv[]){
 
    cout << "Hello world" << endl;

    btree * root = buildTree(&cin);

    cout << "Built the tree" << endl;

    traverse(root);
    return 0;
}
