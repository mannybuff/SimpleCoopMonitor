#pragma once
#include "function.h"
using namespace std;

class Animal {
  protected:
    string type;
    string name;
    string sex;

  public:
    Animal();
    Animal(string newType, string newName, string newSex);

    virtual string getType() const = 0;
    string getName() const;
    string getSex() const;

    void setType(string newType);
    void setName(string newName);
    void setSex(string newSex);
    void printAnimal(ostream& o);

    virtual ~Animal() {}

};