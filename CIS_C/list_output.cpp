//This program calcuates the squares and cubes of 1-10 and prints the numbers in a table.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
   cout << "number" << "\t" << "square" << "\t" << "cube" << "\t" << endl;
   cout << "------" << "\t" << "------"  << "\t" << "------"  << "\t" << endl;
   cout << 1 << "\t" << pow(1,2)  << "\t" << pow(1,3)  << "\t" << endl;
   cout << 2 << "\t" << pow(2,2)  << "\t" << pow(2,3)  << "\t" << endl;
   cout << 3 << "\t" << pow(3,2)  << "\t" << pow(3,3)  << "\t" << endl;
   cout << 4 << "\t" << pow(4,2)  << "\t" << pow(4,3)  << "\t" << endl;
   cout << 5 << "\t" << pow(5,2)  << "\t" << pow(5,3)  << "\t" << endl;
   cout << 6 << "\t" << pow(6,2)  << "\t" << pow(6,3)  << "\t" << endl;
   cout << 7 << "\t" << pow(7,2)  << "\t" << pow(7,3)  << "\t" << endl;
   cout << 8 << "\t" << pow(8,2)  << "\t" << pow(8,3)  << "\t" << endl;
   cout << 9 << "\t" << pow(9,2)  << "\t" << pow(9,3)  << "\t" << endl;
   cout << 10 << "\t" << pow(10,2)  << "\t" << pow(10,3)  << "\t" << endl;
   
   

}
