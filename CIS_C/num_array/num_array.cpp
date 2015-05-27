//Assignment 10
//This program creates a NumericArray class, which
//is used to take a user's array and finds the highest, lowest,
//and average number in the array. THe user will also be able to
//see a chosen element in the array.

#ifndef NumericArray_H
#define NumericArray_H
#include <iostream>
#include <cstdlib>  //For exit function

using namespace std;

class NumericArray
{
	private:
		double *classArray;        //Pointer to Array
		int arraySize;             //Hold array size when memory is dynamically allocated
		
	
	public:
		NumericArray(int);                     //Constructor
		NumericArray(const NumericArray &);    //Copy Constructor
        ~NumericArray();                       //Deconstructor
		
		void setElements(double, int);        
		void setSize(int);

		//
		void outOfBoundsError()                 //Out Of Bounds Checker
		{
			cout << "ArrayIndexOutOfBoundsException: An attempt was made to access an element using an invalid subscript.";
			exit(0);
		}
		int getSize() const;                   //returns array size      
		double getHighNum() const;             //Returns Highest number inputed
		double getLowNum() const;              //Returns Lowest number inputed
		double getAvgNum();                    //Returns the average number of the array
		
		double& operator[](const int &index)                            //Overload [] operator 
		{
			if(index < 0 || index > arraySize)
				outOfBoundsError();
			return classArray[index];
		}
		const NumericArray operator=(const NumericArray &right)        //Overload = operator
		{
			delete [] classArray;

			arraySize = right.arraySize;
			classArray = new double[arraySize];
			for(int count = 0; count < arraySize; count++)
			{
				classArray[count] = right.classArray[count];
			}

			return *this;
		}

};


#endif
      
      
