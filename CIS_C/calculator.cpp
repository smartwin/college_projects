//Assignment 02
//This program prompts the user to input two integers.
//It then displays the sum, difference, product,the quotient, and average of the numbers inputed.
#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

int main()
{
   //User Documentation
   cout << "Input 2 integers when prompted and" 
           "The program will print their sum, difference, product, quotient,"
           "remainder, and average \n" << endl;

   //Declarations 
   int num1;        //User's firt number
   int num2;        //User's second number
   
   //Prompt to recieve user input
   cout << "Please enter your first number: ";
   cin >> num1;
   cout << "Please enter your second number: ";
   cin >> num2;
   
   //Display user's numbers
   cout << "\n";
   cout << "The numbers are " << num1 << " and " << num2 << ".\n" << endl;
   
   
   //Calulations for User's two integer
   int sum = num1+num2;
   int difference = num1-num2;
   int product = num1*num2;
   int quotient = num1/num2;
   int remainder = num1%num2;
   double average = sum /2.0;
   
   //Display the calculations 
   cout << "sum: " << sum << endl;
   cout << "difference: " << difference << endl;
   cout << "product: " << product << endl;
   cout << "quotient: " << quotient << endl;
   cout << "remainder: " << remainder << endl;
   cout << "average: " << setprecision(2) << average << endl;
}  
