#include "function.h"

void InitialChickAdd(istream& i, Linked& a) {
  string tempStr;
  int newEggs;
  getline(i, tempStr, ',');
  if (tempStr == "Chicken") {
    Chicken* newChick = new Chicken;
    getline(i, tempStr, ',');
    newChick->setName(tempStr);
    getline(i, tempStr, ',');
    newChick->setSex(tempStr);
    getline(i, tempStr, ',');
    newEggs = stoi(tempStr);
    newChick->setEggsLayed(newEggs);
    a.addNodeOrdered(newChick);
    cout << "Added Chicken: " << newChick->getName() << endl;
  }
  // Additional animal option can be added here. 
  else{
    cout << "Error: Invalid Animal Type" << endl;
  }
  return;
}
// This function is going to exploit the fixed nature of this line of text from file.
void LoadExpenseVector(istream& i, vector<Expense>& v) {
  string tempStr;
  float tempVal;
  Expense newExpense;
  // First value is a float for this line.
  getline(i, tempStr, ',');
  tempVal = stof(tempStr);
  newExpense.cost = tempVal;
  // Second value is a string.
  getline(i, tempStr, ',');
  newExpense.type = tempStr;
  v.push_back(newExpense);
  // Push the Expense on to the Expense vector v.
  // Get next entries and build next Expense.
  getline(i, tempStr, ',');
  tempVal = stof(tempStr);
  newExpense.cost = tempVal;
  getline(i, tempStr, ',');
  newExpense.type = tempStr;
  v.push_back(newExpense);
  // Get third Expense struct.
  getline(i, tempStr, ',');
  tempVal = stof(tempStr);
  newExpense.cost = tempVal;
  getline(i, tempStr, ',');
  newExpense.type = tempStr;
  v.push_back(newExpense);
}

void PrintOtherMenu(){
  cout << "Sorry to inform you of this, but we only have chickens right now. Check back another time." << endl;
  return;
}

void PrintChickMenu(){
  cout << "CHICKEN OPTIONS:" << endl;
  cout << " Please choose from the following options:" << endl;
  cout << "  C: Collect eggs from the coup." << endl;
  cout << "  A: Add a new chicken to the coup." << endl;
  cout << "  R: Remove a chicken from the coup." << endl;
  cout << "  L: List all the chickens." << endl;
  cout << "  E: Exit to Main menu." << endl;
  cout << "What is your choice?  " << endl;
}

void PrintMenu(){
  cout << "MAIN MENU:" << endl;
  cout << " Please choose from the following options:" << endl;
  cout << "  C: Chicken menu." << endl;
  cout << "  O: Other animal menu." << endl;
  cout << "  L: List all animals." << endl;
  cout << "  E: Expense menu." << endl;
  cout << "  Q: Quit program." << endl;
  cout << "What is your choice?  ";
}
void PrintExpenseMenu(){
  cout << "EXPENSE MENU:" << endl;
  cout << " Please choose from the following options:" << endl;
  cout << "  P: Print all costs." << endl;
  cout << "  I: Increase a cost." << endl;
  cout << "  R: Return to Main menu." << endl;
  cout << "What is your choice?   ";
}

void RunExpenseMenu(vector<Expense>& e){
  PrintExpenseMenu();
  string tempStr;
  char choice;
  int in, tot = 0;
  size_t i;
  getline(cin, tempStr);
  choice = toupper(tempStr[0]);
  while (choice != 'R'){
    // User wants to print total cost.
    if (choice == 'P'){
      setprecision(2);
      cout << "Printing all expenses:" << endl;
      for (i = 0; i < e.size(); ++i){
        cout << e.at(i).type << ":  $" << e.at(i).cost << endl;
        tot += e.at(i).cost;
      }
      cout << "Total Expense costs:   $" << tot << endl;
    }
      // User wants to increase the total of an expense entry.
    else if (choice == 'I'){
      float inc;
      cout << "Choose expense type to increase:   " << endl;
      for(i = 0; i < e.size(); ++i){
        cout << i+1 << ") " << e.at(i).type << endl;
      }
      getline(cin, tempStr);
      // Using Try/Catch block for converting to ints & floats.
      try {
        in = stoi(tempStr);
        if (in < 1 || in > e.size()){
          throw invalid_argument("Invalid choice");
        }
        else {
          cout << "How much is the increase($#.##)? $";
          getline(cin, tempStr);
          inc = stof(tempStr);
          cout << "Increasing " << e.at(in-1).type << " by $" << inc << endl;
          cout << e.at(in-1).cost << " + " << inc << " = ";
          e.at(in-1).cost += inc;
          cout << e.at(in-1).cost << endl;
        }
      }
      catch(invalid_argument& e){
        cout << "Error: Invalid choice." << endl;
        continue;
      }      
    }
    else {
      cout << "Invalid choice. Please try again." << endl;
    }
    PrintExpenseMenu();
    cout << "What would you like to do next?" << endl;
    getline(cin, tempStr);    
  }
  return;
}
void RunChickMenu(Linked& a){
  PrintChickMenu();
  string tempStr;
  char choice;
  getline(cin, tempStr);
  choice = toupper(tempStr[0]);
  while (choice != 'E'){
    // User wants to collect the eggs.
    if (choice == 'C'){
      // This gets more interesting as I need to iterate through the linked list without using the linked functions.
      cout << "Let's collect the eggs." << endl;
      int eggs, iter = 0;      
      Node* tempPtr = a.getHeadPtr();      
      while (tempPtr != nullptr && tempPtr->data->getType() == "Chicken" && tempPtr->data->getSex() == "Female"){        
        cout << "Collecting eggs for lady chicken #" << iter << ": " << tempPtr->data->getName() << endl;
        ++iter; 
        cout << "How many eggs were layed?" << endl;
        getline(cin, tempStr);
        try{
          eggs = stoi(tempStr);
          // If the number entered needs to be added to total eggs layed. 0 is means no update is required.
          if (eggs > 0) {
            // Cast the Animal* to a Chicken*. Make a copy of the Chicken object.
            Chicken* newChick = dynamic_cast<Chicken*> (tempPtr->data);
            Chicken* updatedChick = new Chicken(*newChick);
            // Update the egg total.
            updatedChick->incEggsLayed(eggs);
            // Update data pointer to updated copy.
            tempPtr->data = updatedChick;
            cout << updatedChick->getName() << " has now layed " << updatedChick->getEggsLayed() << " eggs." << endl;
            delete newChick;
          }
          else if (eggs == 0) {continue;}
          else { cout << "Invalid number. Moving on to next entry." << endl;}
        }
        catch(invalid_argument& e){
          cout << "Error: Invalid entry." << endl;
          continue;
        }
        tempPtr= tempPtr->nextPtr;
      }
      
    }
      // User wants to Add a chicken to the Linked List.
    else if (choice == 'A'){
      Chicken* newChick = new Chicken;
      cout << "Congratulations! You got a new chicken!" << endl;
      cout << "What is the new chicken's name? " << endl;
      // Inquire and fill new chicks name.
      getline(cin, tempStr);
      newChick->setName(tempStr);
      cout << "What is the new chicken's sex? " << endl;
      // Inquire/Fill new chick's sex. Default is Female. Using first char for entry (allows for mistypes after).
      getline(cin, tempStr);
      choice = toupper(tempStr[0]);
      if (choice == 'F' || choice == 'M'){
        if (choice == 'F'){newChick->setSex("Female");}
        else if(choice == 'M'){newChick->setSex("Male");}
      }
      else {
        cout << "Invalid Sex. Default value \"Female\" will be used." << endl;
      }
      // EggsLayed is set to 0 by default.
      a.addNode(newChick);
    }
      // User wants to remove a chicken from the Linked List.
    else if (choice == 'R'){
      cout << "Which chicken will be removed from the coup?" << endl;
      a.printSelected("Chicken");
      getline(cin, tempStr);
      a.delNode(tempStr);
    }
    else if (choice == 'L'){
      a.printSelected("Chicken");
    }
    else {cout << "ERROR: Invalid choice. Please try again." << endl;}
    PrintChickMenu();
    getline(cin, tempStr);
    choice = toupper(tempStr[0]);
  }
}
void RunMainMenu(Linked& a, vector<Expense>& e) {
  PrintMenu();
  string tempStr;
  char userInput;
  getline(cin, tempStr);
  userInput = toupper(tempStr.at(0));
  while (userInput == 'Q'){
    if (userInput == 'C' || userInput == 'O' || userInput == 'L' || userInput == 'E') {
      // User wants to deal with expenses.
      if (userInput == 'E'){
        RunExpenseMenu(e);
      }
        // User wants to see the other animal menu. Hint: there are no other animals for now.
      else if (userInput == 'O'){
        PrintOtherMenu();
      }
        // User wants a list of all animals.
      else if (userInput == 'L'){
        a.printList(cout);
      }
        // User wants to use the chicken menu.
      else if (userInput == 'C') {
        RunChickMenu(a);
      }
    }
    else {
      cout << "Invalid option. Please try again." << endl;
    }
    PrintMenu();
    getline(cin, tempStr);
    userInput = toupper(tempStr.at(0));
  }
  cout << "You've chosen to Quit the program. Thank you." << endl;
  cout << "Have a nice day!" << endl;
  return;
}

