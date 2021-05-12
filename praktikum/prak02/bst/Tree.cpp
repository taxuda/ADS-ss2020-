/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Tree::addNode(std::string name, int age, double income, int plz) {
    int pos = age + income + plz;
    TreeNode* newNode = new TreeNode(pos, NodeIDCounter,
                                     name, age, income, plz);
    NodeIDCounter++;

    // binary search leaf node to add
    TreeNode* curr = anker;
    TreeNode* parentNode = NULL;
    while(curr){
        parentNode = curr;
        if(pos <= curr->getNodePosID()){
            curr = curr->getLeft();
        }else{
            curr = curr->getRight();
        }
    }

    // add new node in tree
    if(parentNode == NULL && curr == anker){
        // tree is empty, new node is root node
        anker = newNode;
    }else{
        if(pos <= parentNode->getNodePosID()){
            parentNode->setLeft(newNode);
        }else{
            parentNode->setRight(newNode);
        }
    }
}

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

bool Tree::search(TreeNode* root, std::string &name){
    if(root == NULL) return false;

    if(root->getName() == name) return true;

    return search(root->getLeft(), name) || search(root->getRight(), name);
}

bool Tree::searchNode(std::string name) {
    bool found = false;
    searchAllNode(anker, name, found);
    //return search(anker, name);
    return found;
}

void Tree::searchAllNode(TreeNode* node, std::string name, bool &found){
        if(node == NULL) return;

        if(node->getName() == name){
            found = true;
            node->print();
        }

    searchAllNode(node->getLeft(), name, found);
    searchAllNode(node->getRight(), name, found);
}

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