#include <iostream>
#include <cstdlib>
#include <sstream>
#include "btree.h"

using namespace std;

const int QUIT = 4;

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

btree * buildTree(string * in){

    int data;

    btree * root;

    stringstream ss;
    
    ss << (*in);

    if(ss.good()){
    
        ss >> data;

        root = new btree(data); 

        while(ss.good()){
            ss >> data;
            insertNode(root, data);
        }

    } else {
        cout << "No value from the input" << endl;
    }

    return root;
}

void inOrderTraversal(btree * root){
    if(root != NULL){
        inOrderTraversal(root->getLeft());
        cout << root->getValue()  << " " ;
        inOrderTraversal(root->getRight());
    }
}

bool searchTree(btree * root, int value){
  
    if(root == NULL)
        return false;
    
    if(value == root->getValue())
        return true;
    
    if(root->getLeft() == NULL && root->getRight() == NULL)
        return false;


    if(value > root->getValue()){
        return searchTree(root->getRight(), value);
    } else {
        return searchTree(root->getLeft(), value);
    }
}

void showMainMenu(){
    cout << endl;
    cout << endl;
    cout << "##########################################" << endl;
    cout << "\t" << "Main Menu" << endl;
    cout << "1. Inorder traversal" << endl;
    cout << "2. Search item in tree" << endl;
    cout << "3. Insert item in tree" << endl;
    cout << "4. Quit" << endl;
    cout << "##########################################" << endl;
    cout << endl;
    cout << endl;
}

int main(int argc, char* argv[]){
 
    string line;
    int option;
    
    cout << "Enter values for the BST: " << endl;

    getline(cin, line);
    
    btree * root = buildTree(&line);
    cout << "Built the tree" << endl;

    showMainMenu();


    cout << "Please enter one of the following options: ";
    cin >> option;

    while(option != QUIT){
        
        if(option == 1){
            cout << "Values inside the tree: " << endl;
            inOrderTraversal(root);
            cout << endl;
        } else if(option == 2){
   
            int item;
            cout << "Enter value to search: ";
            cin >> item;
            
            if(searchTree(root, item))
                cout << item << " is inside the tree" << endl;
            else
                cout << item << " is not inside the tree" << endl;

        } else if(option == 3){
            int item;
            cout << "Enter value to insert: ";
            cin >> item;

            insertNode(root, item);
        } else {
            option = QUIT;
        }

        showMainMenu();
        cout << "Please enter one of the following options: ";
        cin >> option;
    }
    return 0;
}
