#include "btree.h"

#ifndef NULL
#define NULL 0
#endif

btree::btree(){
    this->left = NULL;
    this->right = NULL;
    this->value = 0;
}

btree::btree(int value){    
    this->value = value;    
    this->left = NULL;
    this->right = NULL;
}

btree::btree(btree * l, btree * r){
    setLeft(l);
    setRight(r);
}

int btree::getValue(){
    return this->value;
}

void btree::setLeft(btree * l){
    this->left = l;
}

void btree::setRight(btree * r){
    this->right = r;
}

btree * btree::getLeft(){
    if(this->left == NULL)
        return NULL;
    return this->left;
}

btree * btree::getRight(){
    if(this->right == NULL)
        return NULL;
    return this->right;
}

bool btree::hasNullPointers(){
    if(getLeft() == NULL || getRight() == NULL)
        return true;
    return false;
}
