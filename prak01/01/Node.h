//
// Created by dat tran on 04.03.21.
//

#ifndef PRAKTIKUM01_NODE_H
#define PRAKTIKUM01_NODE_H
class Node
{
public:
    int key;
    Node * next, * prev;
public:
    Node();
    Node(int key, Node * next = 0, Node * prev = 0);
    ~Node();
};
#endif //PRAKTIKUM01_NODE_H
