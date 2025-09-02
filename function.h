#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include "animal.h"
#include "chicken.h"
#include "linked.h"

struct Expense {
    std::string type;
    float cost;
};

void InitialChickAdd(std::istream& i, Linked& a);
void LoadExpenseVector(std::istream& i, std::vector<Expense>& e);
void PrintOtherMenu();
void PrintChickMenu();
void PrintMenu();
void PrintExpenseMenu();
void RunExpenseMenu(std::vector<Expense>& e);
void RunChickMenu(Linked& a);
void RunMainMenu(Linked& a, std::vector<Expense>& e);