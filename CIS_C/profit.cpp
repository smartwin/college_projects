//Assignment 2b
//This program will calculate a theater's 
//gross and net box office profit for a night. 


#include <iostream>
#include <iomanip>
#include <cstring>
#include "formatNumber.h"

using namespace std;

int main()
{
   //Declarations
   int adult, child;
   const double ADULT_PRICE= 12.00, CHILD_PRICE= 9.00;
   string movieTitle;
   
   //User Documenation
   cout << "Please enter the number of adult and children"
           "tickets you plan to purchase for a specfic movie"
           "title. The profit made by the theater will be calculated." << endl;
   
   //Obtain user input for movie title and number of tickets planning to purchase
   cout << "Please enter a movie title: ";
   getline(cin, movieTitle);
   cout << "Please enter the number of adults planning to watch the movie: ";
   cin >> adult;
   cout << "Please enter the number of children"
           "planning to watch the movie: ";
   cin >> child; 
   
   //Calculations
   double adultProfit = adult * ADULT_PRICE;
   double childProfit = child * CHILD_PRICE;
   double gross = adultProfit + childProfit;
   double net = gross * 0.20;
   double distributor = gross - net;
   
   //Display Number of Tickets Sold to User
   cout << "Movie Tile:" << setw(45) << movieTitle << endl;
   cout << "Adult Tickets Sold:" << setw(20) << formatNumber(adult) << endl;
   cout << "Child Tikets Sold:" << setw (21) << formatNumber(child) << endl;
   //Display the profit made by theater
   cout << fixed << setprecision(2) << showpoint;
   cout << "Goss Box Office Profit:" << setw(18) << formatNumber(gross, 1) << endl;
   cout << "Net Box Office Profit:" << setw(19) << formatNumber(net, 1) << endl;
   cout << "Amount Paid to the Distributor:" << setw(10) << formatNumber(distributor, 1) << endl;
}
