#pragma once
#include "animal.h"
#include <string>
#include <iostream>

class Chicken : public Animal {
protected:
    int eggsLayed;

public:
    Chicken();
    Chicken(std::string newType, std::string newName, std::string newSex, int newEggsLayed);

    std::string getType() const override;
    int getEggsLayed() const;

    void setEggsLayed(int newEggsLayed);
    void incEggsLayed(int incEggs);
    void printAnimal(std::ostream& o) override;
    ~Chicken() {}
};