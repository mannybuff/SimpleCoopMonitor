#include "function.h"

// Loads initial Chicken data from input stream.
void InitialChickAdd(std::istream& i, Linked& a) {
    std::string tempStr;
    int newEggs;
    std::getline(i, tempStr, ',');
    if (tempStr == "Chicken") {
        Chicken* newChick = new Chicken;
        std::getline(i, tempStr, ',');
        newChick->setName(tempStr);
        std::getline(i, tempStr, ',');
        newChick->setSex(tempStr);
        std::getline(i, tempStr, ',');
        newEggs = std::stoi(tempStr);
        newChick->setEggsLayed(newEggs);
        a.addNodeOrdered(newChick);
    } else {
        std::cout << "Error: Invalid Animal Type" << std::endl;
    }
}

// Loads expense data from input stream into vector.
void LoadExpenseVector(std::istream& i, std::vector<Expense>& v) {
    std::string tempStr;
    float tempVal;
    Expense newExpense;
    std::getline(i, tempStr, ',');
    tempVal = std::stof(tempStr);
    newExpense.cost = tempVal;
    std::getline(i, tempStr, ',');
    newExpense.type = tempStr;
    v.push_back(newExpense);

    std::getline(i, tempStr, ',');
    tempVal = std::stof(tempStr);
    newExpense.cost = tempVal;
    std::getline(i, tempStr, ',');
    newExpense.type = tempStr;
    v.push_back(newExpense);

    std::getline(i, tempStr, ',');
    tempVal = std::stof(tempStr);
    newExpense.cost = tempVal;
    std::getline(i, tempStr, ',');
    newExpense.type = tempStr;
    v.push_back(newExpense);
}

void PrintOtherMenu() {
    std::cout << "Currently, only chickens are supported. Check back for updates." << std::endl;
}

void PrintChickMenu() {
    std::cout << "CHICKEN OPTIONS:" << std::endl;
    std::cout << "  C: Collect eggs from the coop." << std::endl;
    std::cout << "  A: Add a new chicken to the coop." << std::endl;
    std::cout << "  R: Remove a chicken from the coop." << std::endl;
    std::cout << "  L: List all chickens." << std::endl;
    std::cout << "  E: Exit to Main menu." << std::endl;
    std::cout << "What is your choice? ";
}

void PrintMenu() {
    std::cout << "MAIN MENU:" << std::endl;
    std::cout << "  C: Chicken menu." << std::endl;
    std::cout << "  O: Other animal menu." << std::endl;
    std::cout << "  L: List all animals." << std::endl;
    std::cout << "  E: Expense menu." << std::endl;
    std::cout << "  Q: Quit program." << std::endl;
    std::cout << "What is your choice? ";
}

void PrintExpenseMenu() {
    std::cout << "EXPENSE MENU:" << std::endl;
    std::cout << "  P: Print all costs." << std::endl;
    std::cout << "  I: Increase a cost." << std::endl;
    std::cout << "  R: Return to Main menu." << std::endl;
    std::cout << "What is your choice? ";
}

// Runs the expense management menu.
void RunExpenseMenu(std::vector<Expense>& e) {
    PrintExpenseMenu();
    std::string tempStr;
    char choice;
    int tot = 0;
    size_t i;
    std::getline(std::cin, tempStr);
    choice = std::toupper(tempStr[0]);
    while (choice != 'R') {
        if (choice == 'P') {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Printing all expenses:" << std::endl;
            for (i = 0; i < e.size(); ++i) {
                std::cout << e.at(i).type << ": $" << e.at(i).cost << std::endl;
                tot += e.at(i).cost;
            }
            std::cout << "Total Expense costs: $" << tot << std::endl;
        } else if (choice == 'I') {
            float inc;
            int in;
            std::cout << "Choose expense type to increase:" << std::endl;
            for (i = 0; i < e.size(); ++i) {
                std::cout << i + 1 << ") " << e.at(i).type << std::endl;
            }
            std::getline(std::cin, tempStr);
            try {
                in = std::stoi(tempStr);
                if (in < 1 || in > static_cast<int>(e.size())) {
                    throw std::invalid_argument("Invalid choice");
                }
                std::cout << "How much is the increase ($#.##)? $";
                std::getline(std::cin, tempStr);
                inc = std::stof(tempStr);
                e.at(in - 1).cost += inc;
            } catch (const std::invalid_argument&) {
                std::cout << "Error: Invalid choice." << std::endl;
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        PrintExpenseMenu();
        std::getline(std::cin, tempStr);
        choice = std::toupper(tempStr[0]);
    }
}

// Runs the chicken management menu.
void RunChickMenu(Linked& a) {
    PrintChickMenu();
    std::string tempStr;
    char choice;
    std::getline(std::cin, tempStr);
    choice = std::toupper(tempStr[0]);
    while (choice != 'E') {
        if (choice == 'C') {
            int eggs, iter = 0;
            Node* tempPtr = a.getHeadPtr();
            while (tempPtr != nullptr && tempPtr->data->getType() == "Chicken" && tempPtr->data->getSex() == "Female") {
                std::cout << "Collecting eggs for chicken #" << iter << ": " << tempPtr->data->getName() << std::endl;
                ++iter;
                std::cout << "How many eggs were laid?" << std::endl;
                std::getline(std::cin, tempStr);
                try {
                    eggs = std::stoi(tempStr);
                    if (eggs > 0) {
                        Chicken* chick = dynamic_cast<Chicken*>(tempPtr->data);
                        if (chick) chick->incEggsLayed(eggs);
                    }
                } catch (const std::invalid_argument&) {
                    std::cout << "Error: Invalid entry." << std::endl;
                }
                tempPtr = tempPtr->nextPtr;
            }
        } else if (choice == 'A') {
            Chicken* newChick = new Chicken;
            std::cout << "Enter the new chicken's name: ";
            std::getline(std::cin, tempStr);
            newChick->setName(tempStr);
            std::cout << "Enter the new chicken's sex (M/F): ";
            std::getline(std::cin, tempStr);
            choice = std::toupper(tempStr[0]);
            if (choice == 'M') newChick->setSex("Male");
            else newChick->setSex("Female");
            a.addNode(newChick);
        } else if (choice == 'R') {
            std::cout << "Which chicken to remove?" << std::endl;
            a.printSelected("Chicken");
            std::getline(std::cin, tempStr);
            a.delNode(tempStr);
        } else if (choice == 'L') {
            a.printSelected("Chicken");
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
        PrintChickMenu();
        std::getline(std::cin, tempStr);
        choice = std::toupper(tempStr[0]);
    }
}

// Runs the main program menu.
void RunMainMenu(Linked& a, std::vector<Expense>& e) {
    PrintMenu();
    std::string tempStr;
    char userInput;
    std::getline(std::cin, tempStr);
    userInput = std::toupper(tempStr[0]);
    while (userInput != 'Q') {
        if (userInput == 'E') {
            RunExpenseMenu(e);
        } else if (userInput == 'O') {
            PrintOtherMenu();
        } else if (userInput == 'L') {
            a.printList(std::cout);
        } else if (userInput == 'C') {
            RunChickMenu(a);
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
        PrintMenu();
        std::getline(std::cin, tempStr);
        userInput = std::toupper(tempStr[0]);
    }
    std::cout << "Program exiting." << std::endl;
}