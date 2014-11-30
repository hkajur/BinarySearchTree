#include <iostream>
#include <cstdlib>
#include <sstream>
#include "btree.h"

using namespace std;

// QUIT will be a constant variable so if I decided to change
// the value of quit from 4 to 5, it will be easier

const int QUIT = 4;

// Declaring functions to be later used in program

void insertNode(btree * root, int value);
bool searchTree(btree * root, int value);
void deleteNode(btree * root, int value);
btree * buildTree(string * in);
void inOrderTraversal(btree * root);
void showMainMenu();

// Defining functions

/*
 * insertNode function
 * ===================
 * Takes in two arguments 
 *      root which of type btree pointer
 *      value which is of type integer
 * Inserts a new btree with the given value
 * Recursively insert the new node somewhere in the tree
 * Where the location of the new created node depends on its value
 *
 */

void insertNode(btree * root, int value){
  
    // For the case where the root value is the same as the input value 
    // In BST there needs to be no duplicate values

    if(value == root->getValue())
        return;

    /* 
     *  If the passed value is greater than the root value of tree
     *  Then insert the node to the right of the tree 
     *  if the right pointer is empty
     *  Otherwise make a recursive call
     *  If the passed value is lower than root value of tree
     *  Then insert node to the left of the tree
     *  If the left pointer is empty
     *  Then make a recursive call
     */

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

/*
 * searchTree function
 * ===================
 * Takes in two arguments 
 *      root which of type btree pointer
 *      value which is of type integer
 * First check if given root is NULL,
 * if it is NULL, return false
 * Otherwise, check if the value inside root node
 * is the same as the value, if they are same, then return true
 * Otherwise recursively check the child nodes of the tree
 */

bool searchTree(btree * root, int value){
  
    if(root == NULL)
        return false;
    
    if(value == root->getValue())
        return true;
    
    if(root->getLeft() == NULL && root->getRight() == NULL)
        return false;

    if(value > root->getValue())
        return searchTree(root->getRight(), value);
    else 
        return searchTree(root->getLeft(), value);
}

/*
 * buildTree function
 * ==================
 * Takes in a argument which is pointer to string
 * First gets the first integer in the string
 * Makes that the root of the tree and then
 * Splits the string by spaces and loops through
 * each integer and inserts that integer into the tree
 */

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

/*
 * inOrderTraversal function
 * =========================
 * Checks if root is null or not
 * If it is not null, calls the function again recursively
 * so it will go to the deepest left node, and then prints
 * the data inside the deepest left node
 * Then it will go to the deepest right node and prints it
 */

void inOrderTraversal(btree * root){
    if(root != NULL){
        inOrderTraversal(root->getLeft());
        cout << root->getValue()  << " " ;
        inOrderTraversal(root->getRight());
    }
}

/*
 * showMainMenu function
 * =====================
 * Prints the menu and the options for the end user
 */

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
    int op;
   
    // Asks the user to input the values for BST followed by newline
    // to signal that there are no more values to add

    cout << "Enter values for the BST: " << endl;
    getline(cin, line);
   
    // Creates the tree based on the string that we got from user
    btree * root = buildTree(&line);
    cout << "Built the tree" << endl;

    do {
        
        // Show the main menu to the user
        showMainMenu();
        cout << "Please enter one of the following options: ";
        cin >> option;
        
        if(option == 1){
            cout << "Values inside the tree: " << endl;
            inOrderTraversal(root);
            cout << endl;
            
            cout << "Enter 0 to return to main menu: ";
            cin >> op; 

        } else if(option == 2){
   
            int item;
            cout << "Enter value to search: ";
            cin >> item;
            
            if(searchTree(root, item))
                cout << item << " is inside the tree" << endl;
            else
                cout << item << " is not inside the tree" << endl;
            
            cout << "Enter 0 to return to main menu: ";
            cin >> op; 

        } else if(option == 3){
            int item;
            cout << "Enter value to insert: ";
            cin >> item;

            insertNode(root, item);
            
            cout << "Enter 0 to return to main menu: ";
            cin >> op; 
        } else {
            option = QUIT;
        }

    } while(option != QUIT);

    delete root;
    return 0;
}
