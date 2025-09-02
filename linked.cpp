#include "linked.h"

Linked::Linked() {
  cout << "Constructor called\n";
  headPtr = nullptr;
  tailPtr = nullptr;
}

Linked::~Linked() {
   cout << "Destructor called\n";
  //Destructor will loop through the list and delete each node
  Node* tempPtr = headPtr;
  Node* delPtr = tempPtr;
  while (tempPtr != nullptr){
      cout << "So sad: " << tempPtr->data->getName() << " is no longer with us." << endl; // Gotta figure out
      tempPtr= tempPtr->nextPtr;
      delete delPtr;
      delPtr = tempPtr;
  }
  headPtr = nullptr;
  tailPtr = nullptr;
}

Node* Linked::getHeadPtr() {
  return headPtr;
}

void Linked::addNode(Animal* d) {
  //Create a new node (set data & pointer values)
  Node* newNode = new Node;
  newNode->data = d;

  //if the list is empty, set head & tail pointers to new node
  if (headPtr == nullptr){
    headPtr = newNode;
    tailPtr = newNode;
  }
  //else add node to the end
  else{
    tailPtr->nextPtr = newNode;
    tailPtr = newNode;
  }
  cout << "New animal " << d->getName() << " has been added to the list." << endl;
}

void Linked::addNodeOrdered(Animal* d) {
  //Create a new node (set data & pointer values)
  Node* newNode = new Node;
  newNode->data = d;
  newNode->nextPtr = nullptr;
  //check for empty list
  if (headPtr == nullptr){
    headPtr = newNode;
    tailPtr = newNode;
  }
  //check to see if newNode goes before headPtr
  // if so adjust headptr
  else if (newNode->data->getName() < headPtr->data->getName()){ 
    newNode->nextPtr = headPtr;
    headPtr = newNode;
  }
  else{
    //loop through to find where to insert new node
    Node* tempPtr = headPtr;
    while (tempPtr->nextPtr != nullptr 
        && tempPtr->nextPtr->data->getName() < newNode->data->getName())
      tempPtr = tempPtr->nextPtr;
    //tempPtr is pointing to the node prior to where newNode will go
    newNode->nextPtr = tempPtr->nextPtr;
    tempPtr->nextPtr = newNode;
    //adjust tailptr if newNode is the last node
    if (tempPtr == tailPtr)
      tailPtr = newNode;
  }
}
void Linked::delNode(string key) {
  //start at the headPtr and loop until you find key or get to the end of the list
  Node* tempPtr = headPtr;
  Node* delPtr;
  //condition 1: delete data at headptr
  if (tempPtr != nullptr &&
      tempPtr->data->getName() == key){
    cout << "Poor " << key << " is no longer with us :(" << endl;
    delPtr = tempPtr;
    headPtr = tempPtr->nextPtr;
    delete delPtr;
    delPtr = nullptr;
    return;
  }  
  //condition 2: delete a value in the middle of the list
  else{
    while (tempPtr != nullptr &&
      tempPtr->nextPtr != nullptr){
      if (tempPtr->nextPtr->data->getName() == key){
        cout << "Poor " << key << " is no longer with us :(" << endl;
        delPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
        //condition 3: delete value at the end of the list
        if (tempPtr->nextPtr == nullptr)
            tailPtr = tempPtr;
        delete delPtr;
        delPtr = nullptr;
        return;
      }
      tempPtr = tempPtr->nextPtr;
    }
  }
}

void Linked::printList(ostream& o) {
  //start at the headPtr and loop - printing data from each node
  //condition: if headPtr is null, print "List is empty"
  if (headPtr == nullptr){
    cout << "The list is empty\n";
  }
  else{
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr){
      tempPtr->data->printAnimal(o);
      tempPtr= tempPtr->nextPtr;
    }
  }
}

void Linked::printSelected(string key) {
  //start search at the headPtr and loop - printing data from matching nodes
  if (headPtr == nullptr){
    cout << "The list is empty\n";
  }
  else{
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr){
      if (tempPtr->data->getType() == key){
        cout << tempPtr->data->getName() << ": " << tempPtr->data->getType() <<  endl;
      }      
      tempPtr= tempPtr->nextPtr;
    }
  }
}