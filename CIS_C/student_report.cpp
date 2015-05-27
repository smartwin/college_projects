// Assignment 7
// This program will read a data file of student test scores.
// It wll take the information and put it into two dynamically allocated arrays.
// The mean, median, and average of the student test scores will be calculated
// and printed to the screen. The two arrays will be sorted in ascending order
// and then also printed to the screen. 


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;

//to sort the student numbers array in ascending order
void numberSort(int [] , int [], int);
//to sort the student exam scores in ascending order
void scoreSort(int [] , int[], int);
//Print the arrays with the student exam score in ascending order
void printScore(int [], int [] , int, int);
//Print the arrays with the student number score in ascending order
void printNumber(int [], int [] , int, int);
//Calculate Statistcs for class
void arrayStats(int [], int [], int);

int main(){

   //Declarations
   int *studentNumber;        //To dynamically allocate an array for the student numbers
   int *studentScore;         //To dynamically allocate an array for the student exam scores
   int count1;                //Accumulator
   int count2;                //Accumulator
   int numOfStudents;         //To hole the number of students  to be printed on report sheet
   ifstream studentReport;    //In put file stream object
   char detail = 'd';         //Variable for detailed report
   char stats = 's';          //Variabel for statistics 
   char response;             //For user response to what kind of report they want
   char repeat;               //To prompt the user to repeat student report
   int outputMax;             //The maximum number of output the users wants to see
   
   //Loop to print report until user quits
   do
   {
      //Obtain the number of students need for grade report
      cout << "Please enter the numbers of student you wish to see an exam score for (5-1000)" << endl;
      cin >> numOfStudents;
   
      //Input Validation
      while(numOfStudents < 5 || numOfStudents > 1000)
      {
         //Check if number of students is less than 5
         if(numOfStudents < 5)
         {
            cout << "The minimum class size is 5. Please enter a number \n";
            cout << "greater than 5 of the number of students you wish to \n";
            cout << "see an exam score for: "; 
            cin >> numOfStudents; 
         }  
   
         //Check if number of students is greater than 1000
         if(numOfStudents  > 1000)
         {
           cout << "The maximum class size is 1000. Please enter a number \n";
           cout << "less than 1000 of the number of students you wish to \n";
           cout << "see an exam score for: "; 
           cin >> numOfStudents; 
         }
      } 
      
      //Dynamically allocate student numbers array and student exam score
      //array to hold enough memory for the grade sheet.
      studentNumber = new int[numOfStudents];
      studentScore = new int[numOfStudents];
      
      //Open Document
      studentReport.open("scores.txt");
      
      //Inputs data into arrays 
      for(count1 = 0; count1 < numOfStudents; count1++)
        studentReport >> studentNumber[count1] >> studentScore[count1];
      
      //Close Document
      studentReport.close();
      
      //Prompt user on what kind of report they want
      cout << "Please enter a letter for what time of report you wished to see. (the default is d) : \n";
      cout << "\t\t d: for a detailed report, which include the student numbers,";
      cout << "and statistics.\n";
      cout << "\t\t\t OR \n";
      cout << "\t\t s: for a report of the statistics only. \n";
      cout << "Please enter now:  ";
      cin >> response;
      response = tolower(response);
      
      //Loop for printing report type
      if(response == detail)
      {
        //Obtain to the number of report needing to be printed at a time
        cout << "Please enter the number of records you would like to see per screen. (default is 15)\n\n";
        cin >> outputMax;
        
        //Set outputMax to default if neccessary
        if(outputMax < 15)
            outputMax = 15;
        
        //Sorting and Printing of student reports and student statistics 
        numberSort(studentNumber, studentScore, numOfStudents);
        printNumber(studentNumber, studentScore, numOfStudents, outputMax);
        scoreSort(studentScore,studentNumber, numOfStudents);
        printScore(studentNumber, studentScore, numOfStudents, outputMax);
        arrayStats(studentScore, studentNumber, numOfStudents);
      }
      else
      {  
        //Printing of only student statistics
        arrayStats(studentScore, studentNumber, numOfStudents);
      }
      
      // Check with user to repeat report
      cout << "Would you like to print another student report? Press Y or N. (Default is N) ";
      cin >> repeat;
            
      //free allocated memory
      delete [] studentNumber;
      delete [] studentScore;
      
   }while(toupper(repeat) == 'Y');
}  

//This function is meant to sort the numbers array in ascending order
//upon recieving it from the main function.The score array will be sorted 
//at the same time to keep student information together. The sorted array 
//will be sent back to the main function in order to be printed. 
void numberSort(int number[], int score[], int size)
{
   //Declarations
   int startScan, minIndex, minValue, tempNum;
   
   //Sorting of numbers array
   for(startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = number[startScan];
      tempNum = score[startScan];
      
      for(int count = startScan + 1; count < size; count++)
      {
         if(number[count] < minValue)
         {
            minValue = number[count];
            tempNum = score[count];
            minIndex = count;
         }
      }
      number[minIndex] = number[startScan];
      score[minIndex] = score[startScan];
      number[startScan] = minValue;
      score[startScan] = tempNum;
   }
}
//This function will recieve the number and scores array
//from the main function. It will sort the score array
//in ascending order with the numbers array being sorted
//at the same time in order to keep student information
//accurate. The sorted array will be sent back to the
//main function 
void scoreSort(int score[], int number[], int size)
{
   //Declarations
   int startScan, minIndex, minValue, tempNum;
   
   //Sortin of scores array
   for(startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = score[startScan];
      tempNum = number[startScan];
      for(int count = startScan + 1; count < size; count++)
      {
         if(score[count] < minValue)
         {
            minValue = score[count];
            tempNum = number[count];
            minIndex = count;
         }
      }
      score[minIndex] = score[startScan];
      number[minIndex] = number[startScan];
      score[startScan] = minValue;
      number[startScan] = tempNum;
   }
}
  
//This function will recieve both the numbers and scores array. Its purpose
//it to print the two arrays after the numbers array has been sorted in
//ascending order. Through the printing of the array, the function will
//keep track of how many lines are printed, so that the user can control
//how many records are printed at a time. 
void printNumber(int number[], int score[], int size, int outputMax)
{
   //Declarations
   int count1;       //Loop counter
   int count2 = 0;   //Line counter for when keep tracking of printing
   cin.ignore();     //To clear input buffer
   
   //Print array
   for(count1 = 0; count1 < size; count1++)
   {
      //Print Report titles
      if(count2 == 0)
       {
         cout << "Student NUMBER Report\n";
            cout << "STUDENT #" << "\t\t" << "SCORE" << endl;
            cout << "---------" << "\t\t" << "-----" << endl;
       }
       
       //Output Tracker to give user control of output
       if(count2 < outputMax)
        {
            
            cout << number[count1] << "\t\t\t\t" << score[count1] << endl;
            count2++;
        }
        
        //Line counter check for when the program needs the user's permission to continue program
        if(count2 == outputMax)
        {
            
            cout << "Press enter to continue...\n";
            count2 = 0;
            cin.ignore();
       }
    }
}

//This function will recieve both the numbers and scores array. Its purpose
//it to print the two arrays after the scores array has been sorted in
//ascending order. Through the printing of the array, the function will
//keep track of how many lines are printed, so that the user can control
//how many records are printed at a time.  
void printScore(int number[], int score[], int size, int outputMax)
{
   //Declarations
   int count1;       //Loop Counter
   int count2 = 0;   //Output Checker
   
   //Printing of sorted scores array
   for(count1 = 0; count1 < size; count1++)
   {
       //Printing of titles 
       if(count2 == 0)
       {
         cout << "Student SCORE Report\n";
            cout << "STUDENT #" << "\t\t" << "SCORE" << endl;
            cout << "---------" << "\t\t" << "-----" << endl;
       }
       
       //Loop to control output
       if(count2 < outputMax)
        {
             
            cout << number[count1] << "\t\t\t" << score[count1] << endl;
            count2++;
        }
        
        //Loop to reset output tracker
        if(count2 == outputMax)
        {
            cout << "Press enter.\n";
            count2 = 0;
            cin.ignore();
       }
    }
}

//This function will only recive the scores function 
//from the main program. It will calculate the elements
//of the array to find the mean, median, and standard deviation.
//It wiill then print out a report of the statistics of the class.
void arrayStats(int score[], int number[], int size)
{
   //Declarations 
   double sum1 = 0;         //Accumlator for mean
   double sum2 = 0;         // sum of the square of the test score
   int count;               //Loop accumulator
   
   //Calculations 
   double square;           //Sqaure of the test score for sample variance
   double mean;
   double median;
   double sampVar;          // sample Variance
   double stdDev;           //Standard Deviation 
   
   //sort exam scores for median
   scoreSort(score, number, size);
   
   //Calculate the median 
   if(size % 2 == 0)
      median = (score[(size/2)-1] + score[(size/2)])/2.0;
   else
      median = score[size/2];
   
   //Calculation for the sum of the student scores
   for(count = 0; count < size; count++)
      sum1 += score[count];
   
   //Calculate the mean
   mean = sum1/ static_cast<double>(size);
   
   //Calcualte the Sample variance
   for(count = 0; count < size; count++)
   {
      square = pow(score[count], 2.0);
      sum2 += square; 
   }
   
   sampVar = (sum2 -(pow(sum1,2)/size))/(size-1.0);
      
   //Calcualte the Standard Deviation
   stdDev = pow(sampVar, 0.5);
   
   //Output
   cout << fixed << setprecision(2) << showpoint;
   cout << "Here are the statistics for the class: \n";
   cout << "Number of students:" << size << endl;
   cout << "Mean..............:" << mean << endl;
   cout << "Median............:" << median << endl;
   cout << "Standard Deviation:" << stdDev << endl;

}
      
         
