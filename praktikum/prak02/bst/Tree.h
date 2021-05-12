/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

using namespace std;

class Tree{
	
private:
    TreeNode* anker;
    int NodeIDCounter;
public:
    Tree(): anker{NULL}, NodeIDCounter{0}{}

    void addNode(std::string name, int age, double income, int plz);

    TreeNode* deleteRoot(TreeNode* root);

    void deleteNode(int nodePosID);

    bool search (TreeNode* r, std::string &name);

    bool searchNode(std::string name);

    void searchAllNode(TreeNode* node, std::string name, bool &found);

    void printPreorder(TreeNode* node);

    void printAll();
    // friend-Funktionen sind fuer die Tests erforderlich und muessen unangetastet bleiben!
    friend TreeNode * get_anker(Tree& TN);
};
