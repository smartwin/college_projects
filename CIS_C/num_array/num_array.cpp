//Assignment 10
//This program creates a NumericArray class, which
//is used to take a user's array and finds the highest, lowest,
//and average number in the array. THe user will also be able to
//see a chosen element in the array
#include "numericArray.h"
#include <iostream>


using namespace std;


//The constructor of the NumericArray class.
//It sets the size of the array and dynamically
//allocates memory for the array. It initializes
//the allocated array to zero.
NumericArray::NumericArray(int s)
{
	arraySize = s; 
	classArray = new double[s];
	for(int count = 0; count < arraySize; count++)
		*(classArray + count) = 0;
}


//This is the copy constructor of the NumericArray class
NumericArray::NumericArray(const NumericArray &s)
{
	arraySize = s.arraySize;
	classArray = new double[arraySize];
	for(int count = 0; count < arraySize; count++)
		*(classArray + count) = *(s.classArray + count);
}

//Deconstructor of the NumericArray class
NumericArray::~NumericArray()
{
	delete[] classArray;
}

//This function will input the user's numbers into the class array 
void NumericArray::setElements(double value, int index)
{
	classArray[index] = value;
}

//This function will set the size of the array
void NumericArray::setSize(int s)
{
	arraySize = s;
}

//This function returns the size of the array
int NumericArray::getSize() const
{
	return arraySize;
}


//This function returns the highest number inputed to the array
double NumericArray::getHighNum() const
{
	double highest = classArray[0];

	for(int count = 0; count < arraySize; count++)
	{
		if(classArray[count] > highest)
			highest = classArray[count];
	}

	return highest;
}

//This function returns the lowest number inputed to the array
double NumericArray::getLowNum() const
{
	double lowest = classArray[0];
	
	for(int count = 0; count < arraySize; count++)
	{
		if(classArray[count] < lowest)
			lowest = classArray[count];
	}

	return lowest;
}

//This function calculates and returns the average of the array
double NumericArray::getAvgNum()
{
	double sum = 0.0;

	for(int count = 0; count < arraySize; count++)
	{
		sum += classArray[count];
	}

	double average = sum/arraySize;

	return average;
}





