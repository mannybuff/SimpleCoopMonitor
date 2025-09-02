#pragma once
#include "animal.h"
#include <string>
#include <iostream>

struct Node {
    Animal* data;
    Node* nextPtr;
};

class Linked {
protected:
    Node* headPtr;
    Node* tailPtr;

public:
    Linked();
    ~Linked();
    virtual void addNode(Animal* d);  	
    virtual void addNodeOrdered(Animal* d);
    Node* getHeadPtr();
    void delNode(std::string name);
    void printList(std::ostream& o);
    void printSelected(std::string key);
};