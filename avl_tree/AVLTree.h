//
// Created by dat tran on 13.05.21.
//

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H
#include "AVLNode.h"

class AVLTree {
public:

    AVLNode* root;

    AVLTree():root{nullptr}{};

    int getHeight(AVLNode* const &node);

    void leftRotation(AVLNode* &node);

    void rightRotation(AVLNode* &node);

    void insertNode(AVLNode* &node, int val);

    bool searchHelper(AVLNode* &node, int val);

    bool searchNode(int val);

    void deleteNode(int val);

    int max(int x, int y){
        return x < y ? y : x;
    }

    void print_levelorder();
};


#endif //AVL_TREE_AVLTREE_H
