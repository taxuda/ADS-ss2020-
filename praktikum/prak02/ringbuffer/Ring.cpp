/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring.cpp
#include "Ring.h"
#include <iostream>

void Ring::addNode(std::string description, std::string data){
    RingNode* neuNode = new RingNode(0, description, data);
   if(anker == nullptr){
       anker = neuNode;
       anker->setNext(anker);
       AnzahlNodes++;
       return;
   }

   // update oldAge of all nodes before add new node
   RingNode* curr = anker;
   do{
       curr->setAge(curr->getAge() + 1);
       curr = curr->getNext();
   }while(curr != anker);

   // add new node
   if(AnzahlNodes < 6){
       neuNode->setNext(anker->getNext());
       anker->setNext(neuNode);
       anker = neuNode;
       AnzahlNodes++;
   }else{
       neuNode->setNext(anker->getNext()->getNext());
       // delete anker->next
       delete anker->getNext();
       anker->setNext(neuNode);
       anker = neuNode;
   }
}

bool Ring::search(std::string data) {
    if(anker == NULL) return false;

    RingNode* curr = anker;
    do{
        if(curr->getData() == data){
            std::cout << "+ Gefunden in Backup: " << curr->getAge()
                        <<", Beschreibung: " << curr->getDescription()
                        <<", Daten: " << curr->getData() << std::endl;
            return true;
        }

        curr = curr->getNext();
    }while(curr != anker);

    std::cout << "+ Datensatz konnte nicht gefunden werden." << std::endl;
    return false;
}

void Ring::print(){
    if(AnzahlNodes == 0){
        std::cout << "Empty!" << std::endl;
        return;
    }

    std::stack<RingNode*> nodes;
    RingNode* curr = anker->getNext();
    int cnt = AnzahlNodes;
    while(cnt){
        nodes.push(curr);
        curr = curr->getNext();
        cnt--;
    }

    while(!nodes.empty()){
        RingNode* tmp = nodes.top();
        nodes.pop();
        std::cout << "OldAge: " << tmp->getAge()
                    << ", Descr: " << tmp->getDescription()
                    << ", Data: " << tmp->getData() << std::endl;
    }
}
////////////////////////////////////
