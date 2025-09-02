#pragma once
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <iostream>
#include "animal.h"
#include "chicken.h"
#include "linked.h"

using namespace std;

struct Expense {
  string type;
  float cost;
};

void InitialChickAdd(istream& i, Linked& a);

void LoadExpenseVector(istream& i, vector<Expense>& e);

void PrintOtherMenu();

void PrintChickMenu();

void PrintMenu();

void PrintExpenseMenu();

void RunExpenseMenu(vector<Expense>& e);

void RunChickMenu(Linked& a);

void RunMainMenu(Linked& a, vector<Expense>& e);





