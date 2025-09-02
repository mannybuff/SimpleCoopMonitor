#include "chicken.h"

Chicken::Chicken() : Animal() {
  type = "Chicken";
  name = "";
  sex = "Female"; // Default will be Female for egg production, obviously.
  eggsLayed = 0;
}

Chicken::Chicken(string newType, string newName, string newSex, int newEggsLayed) :
  Animal(newType, newName, newSex) {
  eggsLayed = newEggsLayed;
}

string Chicken::getType() const {
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

void Chicken::printAnimal(ostream& o){
  o << type << "," << name << "," << sex << "," << eggsLayed << endl;
}