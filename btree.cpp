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
}

btree::btree(btree * l, btree * r){
    this->left = l;
    this->right = r;
}

int btree::getValue(){
    return this->value;
}
