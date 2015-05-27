// Assignment 04
// This program will test a student's math skiils
// by asking them addition, subtraction, or division
// problems. The program will then give the user feedback
// on their answer.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//This function will generate and return the
//random positive messages that will be 
//outputted to the user for answering
//a questions correctly
int positiveMessage(int option)
{
   //Constants for positive messages
   const int POSITIVE_ONE = 1,
             POSITIVE_TW0 = 2,
             POSITIVE_THREE = 3,
             POSITIVE_FOUR = 4;
   
   //Random number generator to choose positive message
   option = 1 + rand() % 4;
   
   //Choosing of random positive message
   switch(option)
   {
      case 1:
      {
         cout << "Very Good! \n\n";
         break;
      }
      case 2:
      {
         cout << "Nice work! \n\n";
         break;
      }
      case 3:
      {
         cout << "Excellent! \n\n"; 
         break;
      }
      case 4:
      {
         cout << "Keep up the good work! \n\n";
         break;
      }
    }
}

//This function will generate and return the
//random negative messages that will be 
//outputted to the user for answering
//questions incorrectly 
int negativeMessage(int option)
{
   //Constants for the negative messages
   const int NEGATIVE_ONE = 1,
             NEGATIVE_TW0 = 2,
             NEGATIVE_THREE = 3,
             NEGATIVE_FOUR = 4;
   
   //Random Number Generator to randomly output negative messages
   option = 1 + rand() % 4;
   
   //Choosing of random negative message
   switch(option)
   {
      case 1:
      {
         cout << "No. Please Try Again. \n\n";
         break;
      }
      case 2:
      {
         cout << "Sorry. That's Not It. \n\n";
         break;
      }
      case 3:
      {
         cout << "No. Don't Give Up. \n\n"; 
         break;
      }
      case 4:
      {
         cout << "Not Yet. Keep Trying. \n\n";
         break;
      }
    }
}

//This function will display the math
//operations in the form of a menu to the user
//It will return the menu option the user chose
//to the main function 
int menuOptions(int menu)
{
   //Constants for menu choices
   const int ADDITION = 1,
             SUBTRACTION = 2,
             DIVISION = 3,
             QUIT_PROGRAM = 999;
             
   //Display Math Operation Options to user 
   cout << "\t\t Math Question types \n\n"
        << "1: Addition\n"
        << "2: Subtraction\n"
        << "3: Multiplication\n"
        << "4: To Quit Program\n\n"
        << "Enter your choice: ";
   cin  >> menu;
   
 
  //Input Validation  
  while (menu < 1 && menu > 4)
  {
     
     cout << "You have chosen an invalid number. Please choose another number: \n\n";
     cout << "\t\t Math Question types \n\n"
          << "1: Addition\n"
          << "2: Subtraction\n"
          << "3: Multiplication\n"
          << "4: To Quit Program\n\n"
          << "Enter your choice: ";
     cin >> menu;
  }
  
  if(menu == 4)
  {
    cout << "You have chosen to quit the program.";
    exit(0);
  }
  else  
    return menu;
}

int main()
{
   //Set up of random number generator
   unsigned num = time(0);
   srand(num);
   
             
   //User's options
   int choice;           //To choose the type of math question the user wants to recieve
   int userAnswer;       //User's answer to math question
   
   //Computer Feedback
   int computerAnswer;   //Program's answer to math question prompted to the user
   int message;          //To output the positive or negative message to the user
   
   
   //User Documentation
   cout << "This program will test your math"
        << " knowdledge by asking you various"
        << " math questions. \n Please choose an option"
        << " between addition, subtraction, or division. /n";
   
   
   //Obtain the user's choice on type of math question
   int option = menuOptions(choice);
   
   //Output math questions to user until they decide to quit
   while(option != 4)
   {
    switch(option)
    {
      case 1:
      {
         //Random Number Generator for math problem
         int num1 = 1 + rand() % 10;
         int num2 = 1 + rand() % 10;
         
         //Obtain the computer's answer of math question
         computerAnswer = num1 + num2;
         
         //User input and evaluation of math question
         do
         {
            cout << "What is " << num1 << " added to " << num2 << " ? (choose 999 to quit program) \n\n";
            cin >> userAnswer;
            
            //Option for user to quit program mid-calculation 
            if(userAnswer == 999)
            {
               cout << "You have chosen to end the program.";
               exit(0);  
            }
            
            //Outputs a negative message if user answered question wrong
            if(userAnswer != computerAnswer)
               negativeMessage(message);
              
         }while(userAnswer != computerAnswer);
         
         //Output for the user if answer is correct
         if(userAnswer == computerAnswer)
         {
            positiveMessage(message);
            break; 
         }
          
         
      }
      case 2:
      {
         //Random number generator for math problem
         int num1 = 1 + rand() % 10;
         int num2 = 1 + rand() % 10;
        
         //Check to ensure the bigger number comes first
         if (num1 > num2)
         {   
            //Obtain the computer's answer 
            computerAnswer = num1 -num2;
            
            //Oput and evaluation user answer
            do
            {
               cout << "What is " << num1 << " minus " << num2 << "? (choose 999 to quit program) \n\n";
               cin >> userAnswer;
               
                //Option for the user to quit mid-calculation
                if(userAnswer == 999)
                {
                  cout << "You have chosen to end the program.";
                  exit(0);
                }
                
                //Oput is user answer's question wrong
                if(userAnswer != computerAnswer)
                  negativeMessage(message);
                
            }while(userAnswer != computerAnswer);
            
            //Oput if user answer's question correct 
            if(userAnswer == computerAnswer)
            {
               positiveMessage(message);
               break;
            }
            //send user back to the menu
            option = menuOptions(choice);
         }     
         else
         {
            //Obtain computer's answer
            computerAnswer = num2 - num1;
            
            //Output and evaluate user's answer
            do
            {
               cout << "What is " << num2 << " minus " << num1 << "?(choose 999 to quit program) \n\n";
               cin >> userAnswer;
               
                //User's option to quit the program mid-calculation
                if(userAnswer == 999)
                {
                  cout << "You have chosen to end the program.";
                  exit(0);
               
                }
                
                //Output for the user if math question answered incorrectly
                if(userAnswer != computerAnswer)
                  negativeMessage(message);
                  
            }while(userAnswer != computerAnswer);
            
            //Output to the user if question answered correctly 
            if(userAnswer == computerAnswer)
            {
               positiveMessage(message);
               break;
            }
         }   
      }
      case 3:
      {
        //Random Number Generator for math problem
         int num1 = 1 + rand() % 10;
         int num2 = 1 + rand() % 10;
         
         //Obtain the computer's answer of math question
         computerAnswer = num1 * num2;
         
         //User input and evaluation of math question
         do
         {
            cout << "What is " << num1 << " multiplied to " << num2 << " ? (choose 999 to quit program) \n\n";
            cin >> userAnswer;
            
            //Option for user to quit program mid-calculation 
            if(userAnswer == 999)
            {
               cout << "You have chosen to end the program.";
               exit(0);  
            }
            
            //Outputs a negative message if user answered question wrong
            if(userAnswer != computerAnswer)
               negativeMessage(message);
              
         }while(userAnswer != computerAnswer);
         
         //Output for the user if answer is correct
         if(userAnswer == computerAnswer)
         {
            positiveMessage(message);
            break; 
         }
          
       }   
     }
    //send user back to the menu
         option = menuOptions(choice); 
   }
   
}
