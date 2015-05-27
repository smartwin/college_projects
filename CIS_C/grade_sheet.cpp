// Assignment 6
// This program will use arrays to create grade sheet for a class.
// The grade sheet will include the students' test scores, average test
// score, as well as their grade in the class. At the end of the grade sheet, 
// the average score for each test will be posted. 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//The function will obtain and keep track of the
//number of students in the class by counting
//the number of lines in the data file. This value
//will be returned to the main function.
int classSize(int size)
{
   size = 0;                  //Loop accumulator
   ifstream studentData;      //Input file stream object
   
   //Open file 
   studentData.open("classData.txt");
   string temp;               //temp string to store data from file 
   
   
   //Error checking of document
   if(studentData)
   {
      //Counts number of lines in data file 
      while(getline(studentData,temp))
         size++;
   }
   else
   {
      cout << "Error: File could not be found;";
      return 0;
   }  
   
   return size;

}

//This function will assign a letter grade to each
//student based off their average test score.
//It will return the letter grade to the main function. 
char gradeCheck(int score)
{
   if(score >= 90)
      return 'A';
   if(score >= 80)
      return 'B';
   if(score >= 70)
      return 'C';
   if(score >= 60)
      return 'D';
   else
      return 'F';
}

int main(){
   
   //User Documentation
   cout << "This program will take a data file of student test scores in a class \n";
   cout << "It will calculate each student's individual test average, their grade \n";
   cout << "based off their average test score, as well as the average test score \n";
   cout << "for each indvidual test. A report sheet will be printed with this information.\n";
   
   
   //constants
   const int CLASS_MAX = 25;   //Maximum number of student in class
   const int TEST_MAX = 4;     //Maximum number of tests each student will take
   
   //Declarations
   string studentName[CLASS_MAX];          //Array of student names 
   char studentGrade[CLASS_MAX];           //Array of student grades
   int studentScore[CLASS_MAX][TEST_MAX];  //Array of student test scores
   double saverage[CLASS_MAX];             //Array of student average 
   double caverage[TEST_MAX];              //Array of Test Averages   
   
   int count1;                    //Loop counter
   int count2;                    //Loop counter for second dimension 
   int size = 0;                      //to be sent to function that will count students in class
   int sizeTotal = classSize(size);   //total of students in classe
   
   
   ifstream studentData;    //input File stream object
   
   //Open file
   studentData.open("classData.txt");
   
   //Read information from data file 
   while(!studentData.eof())
   {
      
      //Obtain student information from data file
      for(count1 = 0; count1 < sizeTotal; count1++)
      {
         
         //Input data into student test scores array
         studentData >> studentScore[count1][0] >> studentScore[count1][1];
         studentData >> studentScore[count1][2] >> studentScore[count1][3];
       
         //Input data into array of student names 
         getline(studentData, studentName[count1]);
         
       }
    }
  
   //Close file
   studentData.close();
   
   //Calculation variables
   double studentAverage;
   char classGrade;
   char sgrade;
   double classAverage;
  
   
   //Calculate the average test score for each test
   for(count2 = 0; count2 < TEST_MAX; count2++)
   {
      double sum1 = 0.0;                 //Sum for Class Test Average
      for(count1 = 0; count1 < sizeTotal; count1++)
      {
         sum1 += studentScore[count1][count2];
      }
      
      //Calculate average test score and store in caverage array
      classAverage = sum1/ sizeTotal;
      caverage[count2] = classAverage;
      
   }
 
   //Calculate individual student's average test score and grade
   for(count1=0; count1 < sizeTotal; count1++)
   {
      double sum2 = 0.0;                 //Sum for Individual Student test Average
      for(count2 = 0; count2 < TEST_MAX; count2++)
      {
         
         sum2+= studentScore[count1][count2];
      }
      
      //Calculate student average and store in saverage array
      studentAverage = sum2/TEST_MAX;
      saverage[count1] = studentAverage;
      
      //Assign student grades
      sgrade = gradeCheck(studentAverage);
      studentGrade[count1] = sgrade;
      
   }  
   
      
   // Print student report on the screen
   cout << fixed << setprecision(2) << showpoint;
   cout << setw(10) << "\t\t\t\t Student Grade Report \t\t\n";
   for(count1 = 0; count1 < sizeTotal; count1++)
   {
      cout << studentName[count1] << "\t";
      
      for(count2 = 0; count2 < TEST_MAX; count2++)
         cout << studentScore[count1][count2] << "\t";
      
      cout << saverage[count1] << "\t\t" << studentGrade[count1] << endl;      
   }
   
   //Print out Average score for each individual test   
   for(count1 = 0; count1 < TEST_MAX; count1++)
   {
     cout << fixed << setprecision(2) << showpoint;
     cout << "\tAverage Score for Test# " << count1 + 1 << ": " << caverage[count1] << endl;
   }
}
