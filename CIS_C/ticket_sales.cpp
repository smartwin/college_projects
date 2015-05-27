//Assignment 2a
//This program will calculate the ticket sales per section
//and total ticket sales at a baseball stadium. 
//The user will be prompted to input the
//number of tickets sold per section. 

#include <iostream>
#include <iomanip>
#include "formatNumber.h"

using namespace std;

int main()
{
   //Declarations
   double a, b, c;
   const int CLASS_A_PRICE = 15;
   const int CLASS_B_PRICE = 12;
   const int CLASS_C_PRICE = 9;
   
   //User Documentation
   cout << "Please enter the number of tickets sold for each section of \n"
            "the softball stadium. The ticket sales for each section and \n"
            "the total ticket sales will be calculated." << endl;
   
   //Obtain the number of tickets sold from user 
   cout << "Please enter the number of tickets sold for section A: ";
   cin >> a;
   cout << "Please enter the number of tickets sold for section B: ";
   cin >> b;
   cout << "Please enter the number of tickets sold for section C: ";
   cin >> c;
   
    //Calculations
   double totalA = a * CLASS_A_PRICE;
   double totalB = b * CLASS_B_PRICE;
   double totalC = c * CLASS_C_PRICE;
   
   //Display table with calculated ticket sales
   cout << "\n";
   cout << fixed << setprecision(2) << showpoint;
   cout << "Total for Class A tickets:" << setw(15) << formatNumber(totalA) << endl;
   cout << "Total for Class B tickets:" << setw(15) << formatNumber(totalB) << endl;
   cout << "Total for Class C tickets:" << setw(15) << formatNumber(totalC) << endl;
   cout << "-----------------------------------------\n";
   cout << "Total Ticket Sales:" << setw(23) <<  formatNumber(totalA + totalB + totalC) << endl;
}
