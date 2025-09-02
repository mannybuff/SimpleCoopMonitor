#include "function.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int main() {
    std::string tempIn;
    Linked newAnimalList;
    std::vector<Expense> expenses;
    std::ifstream inFile("couplist.txt");
    if (!inFile.is_open()) {
        std::cout << "Error: Failed to open input file." << std::endl;
        return 1;
    }

    std::getline(inFile, tempIn);
    while (inFile.good()) {
        std::stringstream inStream(tempIn);
        if (std::isalpha(inStream.peek())) {
            InitialChickAdd(inStream, newAnimalList);
        } else if (std::isdigit(inStream.peek())) {
            LoadExpenseVector(inStream, expenses);
        }
        std::getline(inFile, tempIn);
    }
    inFile.close();

    RunMainMenu(newAnimalList, expenses);

    std::ofstream outFile("couplist.txt");
    if (!outFile.is_open()) {
        std::cout << "Error: Failed to open output file." << std::endl;
        return 1;
    }
    std::stringstream outStream;
    newAnimalList.printList(outStream);
    for (size_t i = 0; i < expenses.size(); ++i) {
        outStream << expenses[i].cost << "," << expenses[i].type << ",";
    }
    outStream << std::endl;
    outFile << outStream.str();
    outFile.close();

    return 0;
}