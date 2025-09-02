#include "chicken.h"

Chicken::Chicken() : Animal() {
    type = "Chicken";
    eggsLayed = 0;
}

Chicken::Chicken(std::string newType, std::string newName, std::string newSex, int newEggsLayed)
    : Animal(newType, newName, newSex) {
    eggsLayed = newEggsLayed;
}

std::string Chicken::getType() const {
    return type;
}

int Chicken::getEggsLayed() const {
    return eggsLayed;
}

void Chicken::setEggsLayed(int newEggsLayed) {
    eggsLayed = newEggsLayed;
}

void Chicken::incEggsLayed(int incEggs) {
    eggsLayed += incEggs;
}

void Chicken::printAnimal(std::ostream& o) {
    o << type << "," << name << "," << sex << "," << eggsLayed << std::endl;
}