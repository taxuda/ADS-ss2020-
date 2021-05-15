/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include <stack>
#include "TreeNode.h"
#include "catch.h"

using namespace std;

class Tree{
	
private:
    TreeNode* anker;
    int NodeIDCounter;
    /* helper functions to searchNode(string): bool */
    bool search (TreeNode* r, std::string &name);
    void searchAllNode(TreeNode* node, std::string name, bool &found);

    /* helper functions to printAll():void */
    void printPreorder(TreeNode* node);

    /* helper functions to addNode(...):void */
    TreeNode* redBlackInsert(TreeNode* node, TreeNode* &newNode, bool parentOnRight);
    void validate(std::stack<TreeNode*>& path);
public:
    Tree(): anker{NULL}, NodeIDCounter{0}{}

    bool split4Node(TreeNode* &node);

    void addNode(std::string name, int age, double income, int plz);

    void rotateTreeRight(TreeNode* &node);

    void rotateTreeLeft(TreeNode* &node);
    // TreeNode* deleteRoot(TreeNode* root);

    // void deleteNode(int nodePosID);

    bool searchNode(std::string name);

    void printAll();

    void printLevelOrder();
    // friend-Funktionen sind fuer die Tests erforderlich und muessen unangetastet bleiben!
    friend TreeNode * get_anker(Tree& TN);
};
