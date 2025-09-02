#include "animal.h"

Animal::Animal() {
    type = "";
    name = "";
    sex = "Female";
}

Animal::Animal(std::string newType, std::string newName, std::string newSex) {
    type = newType;
    name = newName;
    sex = newSex;
}

std::string Animal::getName() const {
    return name;
}

std::string Animal::getSex() const {
    return sex;
}

void Animal::setType(std::string newType) {
    type = newType;
}

void Animal::setName(std::string newName) {
    name = newName;
}

void Animal::setSex(std::string newSex) {
    sex = newSex;
}

void Animal::printAnimal(std::ostream& o) {
    o << type << "," << name << "," << sex << std::endl;
}