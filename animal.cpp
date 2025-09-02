#include "animal.h"

Animal::Animal() {
  type = "";
  name = "";
  sex = "Female";
}

Animal::Animal(string newType, string newName, string newSex) {
  type = newType;
  name = newName;
  sex = newSex;
}

string Animal::getName() const {
  return name;
}

string Animal::getSex() const {
  return sex;
}

void Animal::setType(string newType) {
  type = newType;
}

void Animal::setName(string newName) {
  name = newName;
}

void Animal::setSex(string newSex) {
  sex = newSex;
}

void Animal::printAnimal(ostream& o) {
  o << type << "," << name << "," << sex << endl;
}