/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
private:
    int oldAge;
    std::string description;
    std::string data;
    RingNode* next;
public:
    RingNode(){}
    RingNode(int const age, std::string const desc, std::string const data):
    oldAge{age}, description{desc}, data{data}, next{nullptr}{}

    int getAge()const {return oldAge;}
    void setAge(int const age){oldAge = age;}

    std::string getDescription()const {return description;}
    void setDescription(std::string const desc){description = desc;}

    std::string getData()const {return data;}
    void setData(std::string const data){RingNode::data = data;}

    RingNode *const getNext()const{return next;}
    void setNext(RingNode* const next){this->next = next;}
};
