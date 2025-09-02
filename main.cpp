#include "function.h"
using namespace std;


int main() {
  // Open selection menu, bring in initial info from .txt file.
  // .txt will need initial values for chickens and expenses.
  //Declare the string
  string tempIn;
  Linked newAnimalList;
  vector<Expense> expenses;
  //Open initial input file and verify.
  ifstream inFile;
  try {
      inFile.open("couplist.txt");
      if (!inFile.is_open()) {
          throw runtime_error("Input file couplist.txt failed to open.");
      }
  }
  catch (const runtime_error& e) {
      cout << "ERROR: " << e.what() << endl;
      inFile.close();
  }    
  
  // File is opened. Saved info ready to be processed. Info is comma separated.
  getline(inFile, tempIn);
  while (inFile.good()) {
    stringstream inStream(tempIn);
    //Animal data will be written type first when program is exited. 
    if (isalpha(inStream.peek())) {          
        InitialChickAdd(inStream, newAnimalList);
    }
    // Expense data will be number first.
    else if (isdigit(inStream.peek())) {
        LoadExpenseVector(inStream, expenses);
    }
    else {break;}
    inStream.clear();
    getline(inFile, tempIn);
  }
  // Close the file.
  inFile.close();

  // Run the main menu for user selection prompt.
  RunMainMenu(newAnimalList, expenses);  
  
  // Start output stream for memory storage.
  stringstream outStream;
  ofstream outCoupList;
  try {
      outCoupList.open("couplist.txt");
      if (!outCoupList.is_open()) {
          throw runtime_error("Output file couplist.txt failed to open.");
      }
  }
  catch (const runtime_error& e) {
      cout << "ERROR: " << e.what() << endl;
      outCoupList.close();
  }
    // Write to the output file.
  newAnimalList.printList(outStream);
  for (size_t i = 0; i < expenses.size(); i++) {
    outStream << expenses[i].cost << "," << expenses[i].type << ",";
  }
  outStream << endl;
  outCoupList << outStream.str();
  outCoupList.close();
  
  return 0;
  
}