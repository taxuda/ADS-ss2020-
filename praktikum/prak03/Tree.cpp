/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include<queue>
#define BLACK false
#define RED true
#define LEFT false
#define RIGHT = true
using namespace std;

/**
 * to check whether a node is 4s-node
 * if true, split that node
 * @return true, when the node is 4s-node
 */
bool Tree::split4Node(TreeNode* &node) {
    if(node == NULL) return false;

    if(node->getRed() == BLACK &&
        node->getRight() && node->getRight()->getRed() == RED &&
        node->getLeft() && node->getLeft()->getRed() == RED){
        // split this node
        // just change the node's color
        if(node == this->anker)
            node->setRed(BLACK);
        else
            node->setRed(RED);

        node->getLeft()->setRed(BLACK);
        node->getRight()->setRed(BLACK);


        return true;
    }

    return false;
}

void Tree::rotateTreeLeft(TreeNode* &node) {
    if(node == NULL) return;
    TreeNode* right = node->getRight();
    node->setRight(right->getLeft());
    right->setLeft(node);

    if(node->getRed() == BLACK){
        right->setRed(BLACK);
        node->setRed(RED);
    }

    node = right;
}

void Tree::rotateTreeRight(TreeNode* &node) {
    if(node == NULL) return;
    TreeNode* left = node->getLeft();
    node->setLeft(left->getRight());
    left->setRight(node);

    if(node->getRed() == BLACK){
        left->setRed(BLACK);
        node->setRed(RED);
    }

    node = left;
}

/**
 * bottom up: validate nodes on search path
 * @param path
 */
void Tree::validate(std::stack<TreeNode*> &path){
    TreeNode* child, *parent, *grandParent;
    while(path.size() >= 3){
        child = path.top();
        path.pop();
        if(child->getRed() == BLACK){
            continue;
        }

        if(child->getRed() == RED && path.top()->getRed() == BLACK){
            path.pop();
            continue;
        }

        if(child->getRed() == RED && path.top()->getRed() == RED){
            // rotation
            parent = path.top();
            path.pop();
            grandParent = path.top();
            path.pop();
            // direction
            TreeNode* tmp = grandParent;
            if(grandParent->getLeft() == parent){
                if(parent->getLeft() == child){
                    // left left insert
                    rotateTreeRight(grandParent);
                }else{
                    // left right insert
                    rotateTreeLeft(parent);
                    grandParent->setLeft(parent);
                    rotateTreeRight(grandParent);
                }
            }else{
                if(parent->getRight() == child){
                    // right right insert
                    rotateTreeLeft(grandParent);
                }else{
                    // right left insert
                    rotateTreeRight(parent);
                    grandParent->setRight(parent);
                    rotateTreeLeft(grandParent);
                }
            }

            // grandParent is anker
            // change anker after rotation
            if(tmp == anker){
                anker = grandParent;
            }

            // after rotation, grandParent node is changed
            // need to update ancestor of this grandParent node
            if(!path.empty()){
                if(path.top()->getNodePosID() < grandParent->getNodePosID()){
                    path.top()->setRight(grandParent);
                }else
                    path.top()->setLeft(grandParent);
            }
        }
    }
}

TreeNode* Tree::redBlackInsert(TreeNode* root, TreeNode *&newNode, bool parentOnRight) {
    if(root == NULL){   // reach leaf node to insert
        root = newNode;
        return root;
    }

    split4Node(root);

    if(newNode->getNodePosID() <= root->getNodePosID()){

        root->setLeft(redBlackInsert( root->getLeft(), newNode, 0) );

        if(root->getRed() == RED
        && root->getLeft() && root->getLeft()->getRed() == RED
        && parentOnRight)
            rotateTreeRight(root);

        if(root->getLeft() && root->getLeft()->getRed() == RED
        && root->getLeft()->getLeft() && root->getLeft()->getLeft()->getRed() == RED)
            rotateTreeRight(root);
    }else{

        root->setRight(redBlackInsert( root->getRight(), newNode, 1 ) );

        if(root->getRed() == RED
        && root->getRight() && root->getRight()->getRed() == RED
        && !parentOnRight)
            rotateTreeLeft(root);

        if(root->getRight() && root->getRight()->getRed() == RED
        && root->getRight()->getRight() && root->getRight()->getRight()->getRed() == RED)
            rotateTreeLeft(root);
    }

    return root;
}

/**
 * Iterative method to add new node
 * 1. top down: traversal from root to insert position,
 * split 4s-node and save nodes in path
 * 2. insert new node at leaf
 * 3. bottom up along the path from inserted position to root:
 * check whether two red nodes flow one another,
 * it's the case, rotation
 * @param name
 * @param age
 * @param income
 * @param plz
 */
void Tree::addNode(std::string name, int age, double income, int plz) {


    int pos = age + income + plz;
    NodeIDCounter++;
    TreeNode* newNode = new TreeNode(pos, NodeIDCounter,
                                     name, age, income, plz);

    /* my recursive method */
    anker = redBlackInsert(anker, newNode, 0);
    anker->setRed(BLACK);

    /* my iterative method
    std::stack<TreeNode*> path;

    // 1. top down: traversal from root to insert position,
    // split 4s-node and save nodes in path
    // binary search leaf node to add
    TreeNode* curr = anker;
    TreeNode* leafNode = NULL;
    while(curr){
        // check whether a node is 4s node
        split4Node(curr);

        leafNode = curr;

        // store the nodes in search path
        path.push(curr);

        if(pos <= curr->getNodePosID()){
            curr = curr->getLeft();
        }else{
            curr = curr->getRight();
        }
    }

    // 2. insert new node at leaf
    // add new node in tree
    if(leafNode == NULL && curr == anker){
        // tree is empty, new node is root node
        anker = newNode;
        anker->setRed(BLACK);       // root is always black
        return;
    }else{
        if(pos <= leafNode->getNodePosID()){
            leafNode->setLeft(newNode);
        }else{
            leafNode->setRight(newNode);
        }
        path.push(newNode);
    }

    // 3. bottom up along the path from inserted position to root:
    // check whether two red nodes flow one another,
    // it's the case, make rotation
    validate(path);
    */
}

/* these delete function is used for binary search tree
 * need to implement other function for red black tree
 /
TreeNode* Tree::deleteRoot(TreeNode *root) {
    // root has none or one child
    if(root == NULL) return NULL;
    if(root->getRight() == NULL) { delete root; return root->getLeft();}
    if(root->getLeft() == NULL) {delete root; return root->getRight();}

    // root has two children
    // find minimum nodes in sub right tree of root;
    TreeNode* parentNode = root;
    TreeNode* newRoot = root->getRight();
    while(newRoot && newRoot->getLeft()){
        parentNode = newRoot;
        newRoot = newRoot->getLeft();
    }

    // delete root and
    // change minimum nodes in sub right as root
    if(root->getRight() == newRoot){
        newRoot->setLeft(root->getLeft());
    }else{
        //                         ParentNode
        //       newRoot                            subrightOfParent
        //                subright_of_newRoot

        parentNode->setLeft(newRoot->getRight());
        //                         ParentNode
        //       subright_of_newRoot                subrightOfParent

        newRoot->setLeft(root->getLeft());
        newRoot->setRight(root->getRight());
    }

    delete root;
    return newRoot;
}

void Tree::deleteNode(int nodePosID) {
    TreeNode* parentNode = NULL;
    TreeNode* beDel = anker;
    bool isFound = false;

    // binary search nodePosID
    while(beDel){
        if(beDel->getNodePosID() == nodePosID){
            isFound = true;
            break;
        }

        parentNode = beDel;
        if(nodePosID < beDel->getNodePosID())
            beDel = beDel->getLeft();
        else
            beDel = beDel->getRight();
    }

    if(!isFound) return;

    if(parentNode == NULL){
        anker = deleteRoot(anker);

    }else if(parentNode->getLeft() == beDel){
        parentNode->setLeft(deleteRoot(beDel));

    }else if(parentNode->getRight() == beDel){
        parentNode->setRight(deleteRoot(beDel));
    }
}
 /
*/

bool Tree::search(TreeNode* root, std::string &name){
    if(root == NULL) return false;

    if(root->getName() == name) return true;

    return search(root->getLeft(), name) || search(root->getRight(), name);
}

/**
 * use to search all nodes when duplicate keys exists
 * @param node
 * @param name
 * @param found
 */
void Tree::searchAllNode(TreeNode* node, std::string name, bool &found){
        if(node == NULL) return;

        if(node->getName() == name){
            found = true;
            node->print();
        }

    searchAllNode(node->getLeft(), name, found);
    searchAllNode(node->getRight(), name, found);
}

bool Tree::searchNode(std::string name) {
    bool found = false;
    searchAllNode(anker, name, found);
    //return search(anker, name);
    return found;
}

/**
 * all these below functions and constants are used
 * to print out all nodes in form of a table
 */
const int id_width = 3;
const int name_width = 12;
const int old_width = 7;
const int income_width = 11;
const int plz_width = 7;
const int pos_width = 7;
const char separator    = ' ';
template<typename T> void printElement(T t, const int& width)
{
    std::cout << right << std::setw(width) << std::setfill(separator) << t << "|";
}

void Tree::printPreorder(TreeNode* node){
    if(node == NULL) return;

    printElement(node->getNodeID(), id_width);
    printElement(node->getName(), name_width);
    printElement(node->getAlter(), old_width);
    printElement(node->getEinkommen(), income_width);
    printElement(node->getPLZ(), plz_width);
    printElement(node->getNodePosID(), pos_width);
    std::cout << std::endl;

    printPreorder(node->getLeft());
    printPreorder(node->getRight());
}

void Tree::printAll() {
    std::cout << "ID |    Name    | Alter | Einkommen |  PLZ  |  Pos  |\n"
                 "---+------------+-------+-----------+-------+-------\n";
    printPreorder(anker);
}


void Tree::printLevelOrder() {
    if(anker == NULL) return;
    std::cout << "Ausgabe in Levelorder als 234-Baum:\n";
    int niv = 0;
    TreeNode* curr = anker;
    TreeNode* endOfLevel = anker;
    queue<TreeNode*>blackNodes;
    blackNodes.push(anker);
    std::cout << "Niv. 0: ";
    while(!blackNodes.empty()){
        curr = blackNodes.front();
        blackNodes.pop();
        // pop 2-3-4 Nodes
        TreeNode* leftCurr = curr->getLeft();
        TreeNode* rightCurr = curr->getRight();
        // push all Kinds of 2-3-4 Node on queue
        if(leftCurr && leftCurr->getRed() == RED){
            // leftCurr belong to this 2-3-4 Node
            if(leftCurr->getLeft())
                blackNodes.push(leftCurr->getLeft());
            if(leftCurr->getRight())
                blackNodes.push(leftCurr->getRight());
        }else if(leftCurr && leftCurr->getRed() == BLACK){
            blackNodes.push(leftCurr);
            leftCurr = NULL;
        }


        if(rightCurr && rightCurr->getRed() == RED){
            // rightCurr belong to this 2-3-4 Node
            if(rightCurr->getLeft())
                blackNodes.push(rightCurr->getLeft());
            if(rightCurr->getRight())
                blackNodes.push(rightCurr->getRight());
        }else if(rightCurr && rightCurr->getRed() == BLACK){
            blackNodes.push(rightCurr);
            rightCurr = NULL;
        }

        // print 2-3-4 Nodes
        std::cout << "(";
        if(leftCurr)
            std::cout << leftCurr->getNodePosID() << ", ";
        std::cout << curr->getNodePosID();
        if(rightCurr)
            std::cout << ", " << rightCurr->getNodePosID();
        std::cout << ") ";

        if(curr == endOfLevel){
            endOfLevel = blackNodes.back();
            std::cout << "\nNiv. " << ++niv << ": ";
        }
    }
}
