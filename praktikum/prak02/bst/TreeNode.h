/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode{
	
private:
    int NodePosID;
    int NodeID;
    std::string Name;
    int Alter;
    double Einkommen;
    int PLZ;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int nPosID, int nID, std::string name, int age, double income, int plz):
    NodePosID{nPosID}, NodeID{nID}, Name{name}, Alter{age}, Einkommen{income}, PLZ{plz}{
        left = NULL; right = NULL;
    }

    int getNodePosID() const {
        return NodePosID;
    }

    void setNodePosID(int nodePosId) {
        NodePosID = nodePosId;
    }

    int getNodeID() const {
        return NodeID;
    }

    void setNodeID(int nodeId) {
        NodeID = nodeId;
    }

    const string &getName() const {
        return Name;
    }

    void setName(const string &name) {
        Name = name;
    }

    int getAlter() const {
        return Alter;
    }

    void setAlter(int alter) {
        Alter = alter;
    }

    double getEinkommen() const {
        return Einkommen;
    }

    void setEinkommen(double einkommen) {
        Einkommen = einkommen;
    }

    int getPLZ() const {
        return PLZ;
    }

    void setPLZ(int plz) {
        PLZ = plz;
    }

    TreeNode *getLeft() const {
        return left;
    }

    void setLeft(TreeNode *left) {
        TreeNode::left = left;
    }

    TreeNode *getRight() const {
        return right;
    }

    void setRight(TreeNode *right) {
        TreeNode::right = right;
    }

    void print();
};
