#pragma once
#include "function.h"
using namespace std;

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
    void delNode(string name);
    void printList(ostream& o);
    void printSelected(string key);
};