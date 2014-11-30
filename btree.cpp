#include "btree.h"

#ifndef NULL
#define NULL 0
#endif

/* 
 * Default constructor
 * ===================
 * Calls the overloaded constructor with integer as paramter
 */
btree::btree(){
    btree(0);
}

/*
 * Overloaded constructor
 * ======================
 * Takes in one argument which is a integer
 * Sets the objects the value to the value of argument
 * Sets the left and right pointers to NULL
 */

btree::btree(int value){    
    this->value = value;    
    this->left = NULL;
    this->right = NULL;
}

/*
 * Overloaded constructor 
 * ======================
 * Takes in two argument which are two pointers to btree
 * Sets the left pointer to the first btree ptr argument
 * Sets the right pointer to the second btree ptr argument
 */

btree::btree(btree * l, btree * r){
    setLeft(l);
    setRight(r);
}

/*
 * Destructor 
 * ==========
 * This will be called when we destroy the root node
 * It will end up deleting the child nodes if they are not null
 * This will free up space after we are done with tree
 */

btree::~btree(){
    if(this->left != NULL)
        delete this->left;
    if(this->right != NULL)
        delete this->right;
}

/*
 * function getValue
 * =================
 * Returns the value of the btree object
 */

int btree::getValue(){
    return this->value;
}

/*
 * function setLeft
 * ================
 * Sets the left btree pointer to argument
 */

void btree::setLeft(btree * l){
    this->left = l;
}

/*
 * function setRight
 * ================
 * Sets the right btree pointer to argument
 */

void btree::setRight(btree * r){
    this->right = r;
}

/*
 * function getLeft
 * ================
 * Returns the left btree pointer
 */

btree * btree::getLeft(){
    if(this->left == NULL)
        return NULL;
    return this->left;
}

/*
 * function getRight
 * ================
 * Returns the right btree pointer
 */

btree * btree::getRight(){
    if(this->right == NULL)
        return NULL;
    return this->right;
}

/*
 * function hasNullPointers
 * ========================
 * Returns true if left pointer or right pointer is null
 * Otherwise it will return false
 */

bool btree::hasNullPointers(){
    if(getLeft() == NULL || getRight() == NULL)
        return true;
    return false;
}
