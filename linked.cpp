#include "linked.h"

// Constructor: Initializes an empty linked list.
Linked::Linked() {
    headPtr = nullptr;
    tailPtr = nullptr;
}

// Destructor: Frees all nodes and associated Animal objects.
Linked::~Linked() {
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        Node* delPtr = tempPtr;
        tempPtr = tempPtr->nextPtr;
        delete delPtr->data;  // Delete the Animal object.
        delete delPtr;
    }
    headPtr = nullptr;
    tailPtr = nullptr;
}

Node* Linked::getHeadPtr() {
    return headPtr;
}

// Adds a new node to the end of the list.
void Linked::addNode(Animal* d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = nullptr;

    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    } else {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
}

// Adds a new node in sorted order based on Animal name.
void Linked::addNodeOrdered(Animal* d) {
    Node* newNode = new Node;
    newNode->data = d;
    newNode->nextPtr = nullptr;

    if (headPtr == nullptr) {
        headPtr = newNode;
        tailPtr = newNode;
    } else if (newNode->data->getName() < headPtr->data->getName()) {
        newNode->nextPtr = headPtr;
        headPtr = newNode;
    } else {
        Node* tempPtr = headPtr;
        while (tempPtr->nextPtr != nullptr && tempPtr->nextPtr->data->getName() < newNode->data->getName()) {
            tempPtr = tempPtr->nextPtr;
        }
        newNode->nextPtr = tempPtr->nextPtr;
        tempPtr->nextPtr = newNode;
        if (tempPtr->nextPtr == nullptr) {
            tailPtr = newNode;
        }
    }
}

// Deletes a node by Animal name if found.
void Linked::delNode(std::string key) {
    if (headPtr == nullptr) return;

    Node* tempPtr = headPtr;
    if (tempPtr->data->getName() == key) {
        headPtr = tempPtr->nextPtr;
        delete tempPtr->data;
        delete tempPtr;
        if (headPtr == nullptr) tailPtr = nullptr;
        return;
    }

    while (tempPtr->nextPtr != nullptr) {
        if (tempPtr->nextPtr->data->getName() == key) {
            Node* delPtr = tempPtr->nextPtr;
            tempPtr->nextPtr = delPtr->nextPtr;
            if (tempPtr->nextPtr == nullptr) tailPtr = tempPtr;
            delete delPtr->data;
            delete delPtr;
            return;
        }
        tempPtr = tempPtr->nextPtr;
    }
}

// Prints the entire list to the output stream.
void Linked::printList(std::ostream& o) {
    if (headPtr == nullptr) {
        o << "The list is empty" << std::endl;
        return;
    }
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        tempPtr->data->printAnimal(o);
        tempPtr = tempPtr->nextPtr;
    }
}

// Prints selected Animals by type.
void Linked::printSelected(std::string key) {
    if (headPtr == nullptr) {
        std::cout << "The list is empty" << std::endl;
        return;
    }
    Node* tempPtr = headPtr;
    while (tempPtr != nullptr) {
        if (tempPtr->data->getType() == key) {
            std::cout << tempPtr->data->getName() << ": " << tempPtr->data->getType() << std::endl;
        }
        tempPtr = tempPtr->nextPtr;
    }
}