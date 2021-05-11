//
// Created by dat tran on 11.05.21.
//

/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring.h
#pragma once
#include<string>
#include "catch.hpp"
#include "RingNode.h"
#include <stack>
//const int MAX_NODES = 6;

class Ring{
private:
    int AnzahlNodes;
    RingNode* anker;
public:
    Ring(){AnzahlNodes = 0; anker = nullptr; }

    void addNode(std::string description, std::string data);

    bool search(std::string data);

    void print();
    ////////////////////////////////////
    // friend Funktionen m�ssen unangetastet bleiben!
    friend RingNode * get_anker(Ring& r);
    friend int get_AnzahlNodes(Ring& r);
};

