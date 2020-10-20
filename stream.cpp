// Author:     Rahib R Laghari
// Course:     CS1136.110
// Date:       10/14/2020
// Assignment: Lesson #7 Part #1
// Compiler:   Xcode

// Description:
// This program imports text documents and reads out data from the documents in a
// "bar chart" using the astrik key (*) to represent $5000 if data is valid, done by
// printing it onto a file called saleschart.txt

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
   // first I name my variables, storeNum will just be store number, dollars is total revenue, i is
   // used in for loop when printing astricks on spreadsheet, and b is used to print the title on the
   // barchart, and make sure it's done only once
   int storeNum;
   int dollars;
   int i;
   int b = 0;
   // prompt user to enter filename, store it in variable filename, and open the file
   // also open outputFile called saleschart.txt to store certain data for the spreadsheet
   cout << "Enter input file name\n";
   string filename;
   cin >> filename;
   ofstream outputFile;
   outputFile.open("saleschart.txt");
   ifstream inputFile;
   inputFile.open(filename);
   // validate file, then print output desired in location desired
   if (inputFile){
      while (inputFile >> storeNum >> dollars){
         if ( 1 <= storeNum and storeNum <= 99 and dollars >= 0) {
            if (b==0){
               outputFile << "SALES BAR CHART\n";
               outputFile << "(Each * equals 5,000 dollars)\n";
            }
               b=1;
            outputFile << "Store" << setw(3) << right << storeNum << ": ";
               for (i = 0; i < dollars/5000; i+=1){
                  outputFile << "*";
            }
            outputFile << "\n";
         }
         else if (dollars < 0){
            cout << "The sales value for store " << storeNum << " is negative";
            cout << "\n";
         }
         else{
            cout << "The store number " << storeNum << " is not valid";
            cout << "\n";
         }
      }
   // if file un-openable, then below error message displayed
   }
   else{
      cout << "File " << "\"" << filename <<"\"" << " could not be opened\n";
   }
   // Finally, close both input and output file
   inputFile.close();
   outputFile.close();
   return 0;
} // end function main
