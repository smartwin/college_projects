// Assignment 08
// The program will verify that a password will
// meet certain specifications. 

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std; 

//Verifies User Password
bool passwordValid(char *);
//Lets user know that password not long enough
void passwordLength();
//Lets user know that password does not contain an uppercase letter
void passwordUpper();
//Lets user know that password does not contain an lowercase letter
void passwordLower();
//Lets user know that password does not contain a number
void passwordNumber();

int main()
{
   //Declarations
   const int SIZE = 100;   //Maximum Array size 
   char password[SIZE];    //Character Array for user input
   
   //User Documentation
   cout << "This program will ask you to enter a password." << endl;
   cout << "It will then verify that the password is at least" << endl;
   cout << "six characters in size, contains at least one uppercase letter" << endl;
   cout << "at least one lowercase letter, and contains at least one number \n\n" << endl;
   
   //Obtain the password from the user
   cout << "Please enter a passowrd that";
   cout << " is at least six characters and contains: " << endl;
   cout << " \t\t One (1) number \n";
   cout << " \t\t One (1) Uppercase Letter \n";
   cout << " \t\t One (1) Lowercase Letter \n";
   cout << "Enter your password now: "; 
   cin.getline(password, SIZE);
  
   //Loop for invalid passwords
   while(passwordValid(password) == false)
   {
      cout << "Please enter a new passowrd.";
      cout << "Enter your password now: "; 
      cin.getline(password, SIZE);
   }
   
   //Output if password is valid 
   cout << "The password: " << password << " is a valid password";
}


// This function will take the character array,
// password, in order to determine if it meets
// criteria stated in the program description
bool passwordValid(char *password)
{
   bool pLength = false;             //Confims the length of the password
   bool pUpper = false;              //Confirms the password contains an uppercase letter
   bool pLower = false;              //Confirms the password contains a lowercase letter
   bool pNumber = false;             //Confirms the passowrd contains a number
   int length = strlen(password);    //Obtains the length of the password array
   int count;                        //Loop Variable Counter
   
   //Loop for password quilifcation check
   for(count = 0; count < length; count++)
   {
      if(length > 6)
         pLength = true;
      if(isdigit(password[count]))
         pNumber = true;
      if(isupper(password[count]))
         pUpper = true;
      if(islower(password[count]))
         pLower = true;
    }
    
    //Output individual for aspects of the user's password that is missing
    if(pLength == false || pUpper == false || pLower == false || pNumber == false)
    {
      cout << "Your password is invalid for the following reasons: " << endl;
      
      if(pLength == false)
         passwordLength();
      if(pUpper == false)
         passwordUpper();
      if(pLower == false)
         passwordLower();
      if(pNumber == false)
         passwordNumber();
      cout << "\n";
      return false;
    }
    else
    {
      return true;
    }
    
     
}


//This function will let the user know
//their password is not long enough
void passwordLength(){
   cout << "Your password needs to be at least 6 characters long." << endl;
}

//This function will let the user know
//their password does not contain an uppercase letter
void passwordUpper()
{
   cout << "Your password needs at least one (1) uppercase letter" << endl;
}

//This function will let the user know
//their password does not contain a lowercase letter
void passwordLower()
{
   cout << "Your password needs at lease one (1) lowercase letter" << endl;
}

//This function will let the user
//know their password does not contain
//a digit
void passwordNumber()
{
   cout << "Your password needs at least one (1) number" << endl;
}
