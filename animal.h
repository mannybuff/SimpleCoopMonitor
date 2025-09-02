#pragma once
#include <string>
#include <iostream>

class Animal {
protected:
    std::string type;
    std::string name;
    std::string sex;

public:
    Animal();
    Animal(std::string newType, std::string newName, std::string newSex);

    virtual std::string getType() const = 0;
    std::string getName() const;
    std::string getSex() const;

    void setType(std::string newType);
    void setName(std::string newName);
    void setSex(std::string newSex);
    void printAnimal(std::ostream& o);

    virtual ~Animal() {}
};