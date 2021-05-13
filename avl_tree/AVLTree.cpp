//
// Created by dat tran on 13.05.21.
//

#include "AVLTree.h"
#include <queue>
#include <iostream>

/*
 * why we need this function ?
 * instead of using ->height !?
 */
int AVLTree::getHeight(AVLNode *const &node) {
    if(node == nullptr)
        return -1;

    return node->height;
}

void AVLTree::insertNode(AVLNode* &node, int val) {
    // 1) creat new node
    if(node == nullptr){
        node = new AVLNode(val);
        return;
    }

    if(val < node->val){
        // 2) insert in left sub tree
        insertNode(node->left, val);
        // 3) balance / rotation
        if(getHeight(node->left) - getHeight(node->right) == 2){
            if(val < node->left->val){  // left left insert
                rightRotation(node);
            }else{                      // left right insert;
                leftRotation(node->left);
                rightRotation(node);
            }
        }
    }else if(node->val < val){
        // 2) insert in right sub tree
        insertNode(node->right, val);
        // 3) balance / rotation
        if(getHeight(node->left) - getHeight(node->right) == -2){
            if(node->right->val < val){ // right right insert
                leftRotation(node);
            }else{                      // right left insert
                rightRotation(node->right);
                leftRotation(node);
            }
        }
    }else ; // do nothing, equal val shouldn't be inserted

    // 4) update height of node after inserting new nodes
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

/*
T1, T2 and T3 are subtrees of the tree
rooted with y (on the left side) or x (on
the right side)
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
Keys in both of the above trees follow the
following order
 keys(T1) < key(x) < keys(T2) < key(y) < keys(T3)
So BST property is not violated anywhere.
 */
void AVLTree::leftRotation(AVLNode *& x) {  // x is imbalanced
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;

    // update height ?
    // node x fist then node y
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    x = y; // change new root
}

/*
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y
  / \                                  / \
 T1  T2                               T2  T3
 */
void AVLTree::rightRotation(AVLNode *& y) { // y is imbalanced
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;

    // update height ?
    // node y fist then node x
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    y = x; // change new root
}

bool AVLTree::searchHelper(AVLNode *&node, int val) {
    if(node == NULL) return false;
    if(node->val == val) return true;
    return searchHelper(node->left, val) || searchHelper(node->right, val);
}

bool AVLTree::searchNode(int val) {
    return searchHelper(root, val);
}

void AVLTree::deleteNode(int val) {

}

void AVLTree::print_levelorder() {
    if(root == NULL){
        std::cout << "Tree is empty!" << std::endl;
    }
    AVLNode* curr = nullptr;
    AVLNode* endOfLevel = root;
    std::queue<AVLNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        curr = nodes.front();
        nodes.pop();
        std::cout << curr->val << " ";
        if(curr->left)
            nodes.push(curr->left);
        if(curr->right)
            nodes.push(curr->right);
        if(curr == endOfLevel){
            std::cout << std::endl;
            endOfLevel = nodes.back();
        }
    }
}
