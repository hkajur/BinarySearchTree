#ifndef BTREE_H
#define BTREE_H

class btree {
    
    btree * left;
    btree * right;
    int value;

    public:
       
        btree();
        btree(int value);
        btree(btree * l, btree * r);
       
        void setLeft(btree * l);
        void setRight(btree * l);

        btree * getLeft();
        btree * getRight();

        bool hasNullPointers();
        int getValue();
};

#endif
