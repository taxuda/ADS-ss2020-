#include "hashtable.h"
#include <iostream>
#define EMPTY -1
using namespace std;

HashTable::HashTable(int size):size{size}, collisionCount{0}, elements{0}{
    hashTable = new vector<int>(size, EMPTY);
}

HashTable::~HashTable()
{
    // https://www.techiedelight.com/delete-vector-free-memory-cpp/
//    hashTable->clear();
//    hashTable->shrink_to_fit();
    vector<int>().swap(*hashTable);
    delete hashTable;
}

int HashTable::hashValue(int item) {
	
	int index = -1; //dummy initialization
	int capacity = hashTable->capacity();
    bool isCollided = false;
    // using quadratic probing
    int i = 0;
    do{
        if(isCollided) collisionCount++;

        // hash function
        index = (item + i * i) % capacity;
        i++;

        isCollided = true;
    }while((*hashTable)[index] != EMPTY);  // lap lai cho den khi nao tim duoc vi tri trong
	return index;
}

int HashTable::insert(int item) {
	
	int index = hashValue(item);
	if((*hashTable)[index] != -1)
	    return false;

    (*hashTable)[index] = item;
    elements++;
    return true;
	//return 0; //dummy return
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() const{
	return this->collisionCount;
}

int HashTable::getSize() const{
	return this->size;
}

int HashTable::getElements() const{
	return this->elements;
}
