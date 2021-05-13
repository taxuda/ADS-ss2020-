//
// Created by dat tran on 13.05.21.
//

#ifndef AVL_TREE_AVLNODE_H
#define AVL_TREE_AVLNODE_H


class AVLNode {
public:
    int val;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int const val):val{val}, left{nullptr}, right{nullptr}, height{0}{}

};


#endif //AVL_TREE_AVLNODE_H
