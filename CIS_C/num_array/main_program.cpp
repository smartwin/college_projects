//Assignment 10
//This program creates a NumericArray class, which
//is used to take a user's array and finds the highest, lowest,
//and average number in the array. THe user will also be able to
//see a chosen element in the array
#include "NumericArray.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
	//User Documentation
	cout << "This program will demonstrate the member functions of the NumericArray class.\n";
	cout << "The user will be prompted to enter the number of elements they wish to have in\nthe ";
	cout << "array. The user will then be asked to input the numbers of their array.\nThe ";
	cout << "highest, lowest, and average numbers will be displayed. The user will then be\nprompted ";
	cout << "on whether they would like to see an element in the array.\nIf yes, they will be\nprompted ";
	cout << "to enter the index of the array element they would like to see.\n\n";
	
	//Declarations
	int numOfElements = 0;                    //Initialize size of array
	NumericArray userArray(numOfElements);    //Define a NumericArray with size numOfElements
	int index;                                //To be used when user requests an element in the array
	char decision = 'y';                      //Give user the option of finding an element in the array 
	char response;                            //For user to respond to prompt

	//Obtain the number of array elements to be used by  the user
	cout << "Please enter the number of elements you would like to add to the array.";
	cin >> numOfElements;

	userArray.setSize(numOfElements);       //Enter the size of the array to be used to NumericArray class member functions

	//Obtain numbers for array from the user
	for(int count = 0; count < numOfElements; count++)
	{
		cout << "Please enter #" << (count+1) << " number you would like to add to array: ";
		cin >> userArray[count];

		userArray.setElements(userArray[count], count);  //Input the values from the user into array to be used in NumericArray member functions
	}

	//Calculations
	double highestNum = userArray.getHighNum(); //Returns highest number
	double lowestNum = userArray.getLowNum();   //Returns lowest number
	double average = userArray.getAvgNum();     //Returns average number of array
	double displaySize = userArray.getSize();   //Returns size of the array

	//Display array stats 
	cout << fixed << setprecision(2) << showpoint;
	cout << "Your array's size is:\t\t " << displaySize << endl;
	cout << "The highest number in the array:\t\t " << highestNum << endl;
	cout << "The lowest number in the array:\t\t " << lowestNum << endl;
	cout << "The average number in the array:\t\t " << average << endl;

	//Prompt user about searching for an array element
	cout << "Would you like to see a number of the array?: ";
	cin >> response;
	response = tolower(response);

	//User searches for array elements until choosing to quit
	while(response == decision)
	{
		cout << "Please enter the index of the element you would like to see: ";
		cin >> index;

		double displayElement = userArray[index];

		cout << "The element number you chose was: " << displayElement << endl;

		cout << "Would you like to look up another element? :";
		cin >> response;
	}
	
	cout << "This is the end of the program.";
	

	

}
