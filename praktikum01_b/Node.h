//
// Created by dat tran on 14.03.21.
//

#ifndef PRAKTIKUM01_B_NODE_H
#define PRAKTIKUM01_B_NODE_H
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
Node::Node()
{
    next = 0;
    prev = 0;
}
Node::Node(int key, Node * next, Node * prev)
{
    this->key = key;
    this->next = next;
    this->prev = prev;
}
Node::~Node()
{
}
#endif //PRAKTIKUM01_B_NODE_H
