//
// Created by dat tran on 14.03.21.
//

#ifndef PRAKTIKUM01_B_NODE_H
#define PRAKTIKUM01_B_NODE_H

template <typename T>
class Node{
public:
    T key;
    Node<T> * next, * prev;
public:
    Node();
    Node(T key, Node<T> * next = 0, Node<T> * prev = 0);
    ~Node();
};

template <typename T>
Node<T>::Node()
{
    next = 0;
    prev = 0;
}

template <typename T>
Node<T>::Node(T key, Node<T> * next, Node<T> * prev)
{
    this->key = key;
    this->next = next;
    this->prev = prev;
}

template <typename T>
Node<T>::~Node()
{
}
#endif //PRAKTIKUM01_B_NODE_H
