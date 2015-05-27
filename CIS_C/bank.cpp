//Assignment 9
//This program will assist the user in creating
//customer bank accounts. The user will be able to
//edit this bank accounts, as well as print them out 

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> 


using namespace std;

struct bankAccount
{
   string name;        //For customer name
   int ID;             //For account ID
   double balance;     //For account balance
};

int bankMenu()
{
   //Declarations
   int option;               //For user to chose from menu
   
      
   //Display menu to user
   cout << "Please choose from one of the following: \n";
   cout << "1: Input Customer Account Information \n";
   cout << "2: Edit Customer Account Information \n";
   cout << "3: Print Customer Accounts \n";
   cout << "4: To quit the program \n";
   cout << "Enter your number choice now: ";
   cin >> option;
    
   //Input Validation
   if(option <= 0 && option > 4)
   {
     cout << "You have chosen an invalid menu option.\n";
     cout << "Please choose from one of the following: \n ";
     cout << "1: Input Customer Account Information \n";
     cout << "2: Edit Customer Account Information \n";
     cout << "3: Print Customer Accounts \n";
     cout << "4: To quit the program \n";
     cout << "Enter your number choice now: ";
     cin >> option;
    }
       
    return option;
}

bankAccount inputAccount(bankAccount customers[], int element)
{
  cin.ignore();
  for(int count = 0; count < element; count++)
  {
      //Get the customer name
      cout << "Please enter the name of customer #" << (count + 1) << ": " << endl;
      getline(cin, customers[count].name);
      
      //Get the customer Account ID
      cout << "Please enter customer #" << (count + 1) << "'s account ID: " << endl;
      cin >> customers[count].ID;
   
      //Get the customer balance
      cout << "Please enter customer  #" << (count + 1) << "'s account balance: " << endl;
      cin >> customers[count].balance;
      
      while(customers[count].balance < 0)
      {
        cout << "A customer's balance cannot be less than 0. \n";
        cout << "Please enter in a new customer balance that ";
        cout << "is greater than 0: \n";
        cin >> customers[count].balance;
      }
   }
}


int main()
{
   //User Documentation 
   cout << "Welcome Customer Account Manager.\nIn the program, you";
   cout << " will be able to enter customer infromation,\nedit already";
   cout << " already existing information. \nAn print a report of the customer";
   cout << " accounts. \n";
   
   //Declarations
   int count;                //Loop Counte
   int numOfAccounts;        //To keep track of the number of account in array
   bankAccount *customers;   //Array to hold accounts
   int ID;                   //To hold the customer account ID
   int option1;              //To be used for user options when making edits
   int index = 0;            //Used as subscript to search for customer ID
   int position = -1;        //To be used to keep track of position in array
   bool exist = false;       //To be used for the results of the search
   
   //Costants
   const int CUSTOMER_INPUT = 1,    //For Bank Main Menu
             ACCOUNT_EDIT = 2,
             PRINT_REPORT = 3,
             QUIT_PROGRAM = 4; 
   const int ID_EDIT = 1,           //For Menu for structure edits
             NAME_EDIT = 2,
             BALANCE_EDIT = 3;

   //Dynamically allocating space for customers array 
   customers = new bankAccount[numOfAccounts];
  
  option1 = bankMenu(); 
  
  while(option1 != 4)
  {     
       switch(option1)
       {
         case CUSTOMER_INPUT:
           cout << "This works";
          //  //Obtain the number of accounts to be held in *customers array
//            cout << "How many accounts do you plan to work with today?: ";
//            cin >> numOfAccounts;
//    
//       //   //Input Validation
// //         while(numOfAccounts < 20)
// //         {
// //             cout << "You have to work with at least 20 accounts at a time.\n";
// //             cout << "Please enter the number of account you plan to work";
// //             cout << " today.";
// //             cin >> numOfAccounts;
// //         } 
//            
//            //Input account information in customers array
//             cout << "Please fill in every field prompted, an incomplete account ";
//             cout << "will not be accepted. \n";
//    
//             for(count = 0; count < numOfAccounts; count++)
//             {   
//                customers[count] = inputAccount(customers, count);
//             }
            break;
         case ACCOUNT_EDIT:
             cout << "You have chosen to edit one of the customer";
             cout << " accounts.\n You will be able to edit any of the";
             cout << " customer accounts in the system. \nPlease enter"; 
             cout << "the customer ID of the customer account you would like to edit:  \n";
             cin >> ID;
   
             //Seach for account ID
             while(index < numOfAccounts && !exist)
             {
                  if(customers[index].ID == ID)
                  {
                     exist = true;      //Mark that ID has been found in array
                     position = index;   //Mark location of found ID in array
                  }
                 index++;
              }      
   
              //Output to user results of search
              while(exist == false)
              {
                  cout << "Sorry, the customer ID you have entered is not in the system. \n";
                  cout << "Please enter a new customer ID: ";
                  cin >> ID; 
               }     
    
               while(exist == true)
               {
                  cout << "You have chosen account number " << ID << "\n";
                  cout << "Please chose a field that needs to be edited: \n";
                  cout << "1: Change Account ID \n";
                  cout << "2: Change Name on Account \n";
                  cout << "3: Change Current Account Balance \n";
                  cout << "4: Go Back to Bank Main Menu/n";
                  cout << "Please enter your choice now:  ";
                  cin >> option1;
               
                  //Input Validation
                  while(option1 < ID_EDIT && option1 > QUIT_PROGRAM)
                  {
                         cout << "You have chosen an invalid number \n";
                         cout << "Please choose one of the options in the menu.";
                         cout << "Please chose a field that needs to be edited: \n";
                         cout << "1: Change Account ID \n";
                         cout << "2: Change Name on Account \n";
                         cout << "3: Change Current Account Balance \n";
                         cout << "4: Go Back to Bank Main Menu/n";
                         cout << "Please enter your choice now:  ";
                         cin >> option1;
                   }
      
                  if(option1 == QUIT_PROGRAM)
                  {
                     cout << "You have chose to return to the main menu.";
                     delete [] customers;
                     exit(0);
                  }
      
                  while(option1 != QUIT_PROGRAM)
                  {
                      switch(option1)
                      {
                        case ID_EDIT:
                        {
                           cout << "You have chosen to edit the account ID";
                           cout << " for account # " << ID << "\nPlease enter a";
                           cout << " new ID Number: ";
                           cin >> customers[position].ID;
               
                           cout << "You have successfully changed the customer ID ";
                           cout << " to " << customers[position].ID << ".\nYou will now";
                           cout << "now be returned to the menu.";
                           break;
                        }  
            
                        case NAME_EDIT:
                        {
                           cout << "You have chosen to edit the name on the ";
                           cout << "account for account #" << ID << "\n Please enter a ";
                           cout << " new name : ";
                           getline(cin, customers[position].name);
                           
                           cout << "You have successfully changed the name on the ";
                           cout << "account to:" << customers[position].name << "\n .You ";
                           cout << "will now be returned to the menu.";
                           break;
                        }  
            
                        case BALANCE_EDIT:
                        {
                           cout << "You have chosen to edit the account balance";
                           cout << "for the account #" << ID << "\n. Please remember ";
                           cout << "that only postive balances will be accepted.\n Please" ;
                           cout << "enter a balance now: ";
                           cin >> customers[position].balance;
                           
                           while(customers[position].balance < 0)
                           {
                              cout << "Account Balances cannot be less than $0";
                              cout << ".\nPlease enter in a new account balance";
                              cout << " greater than 0: ";
                              cin >> customers[position].balance;
                            }
               
                            cout << "You have successfully changed the accont balance to: $";
                            cout << customers[position].balance << ".\n You will not be returned ";
                            cout << "to the menu.";
                            break; 
                          }
                   }
               }
           }
           break;
         case PRINT_REPORT:
            cout << "\tCustomer Reports\n";
            cout << "Account ID" << "\t\t\t" << "Customer Name" << "\t\t\t" << "Account Balance" << endl;
            cout << "-----------" <<"\t\t\t" << "-------------" << "\t\t\t" << "---------------" << endl;  
            for(count = 0; count < numOfAccounts; count++)
            {
               cout << customers[count].ID << "\t\t\t" << customers[count].name << "\t\t\t" << customers[count].balance;
            }
            break;
       } 
     }
    delete []customers;
    cout << "You have chosen to quit the program.";
}
