#pragma once
#include "function.h"
using namespace std;

class Chicken : public Animal {
  protected:
    
    int eggsLayed;

  public:
    Chicken();
    Chicken(string newType, string newName, string newSex, int newEggsLayed);

    string getType() const override;
    int getEggsLayed() const;
     
  
    void setEggsLayed(int newEggsLayed);
    void incEggsLayed(int incEggs);
    void printAnimal(ostream& o);
    ~Chicken() {}
};