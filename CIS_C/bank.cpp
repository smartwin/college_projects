// Myia Dickens
// 1245624
// Assignment 09
// The program will simulate a customer account manager
// The user will be able to input a customer's account information
// using structures. The user will also be able to edit the information inputed,
// as well as print the customer accounts. 
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
   if(option < 1 && option > 4)
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

bankAccount accountInput(int count)
{
   cin.ignore();
   bankAccount tempCustomer;
   
   cout << "Please enter customer #" << (count + 1) << "'s name: ";
   getline(cin, tempCustomer.name);
   cout << "Please enter customer #" << (count + 1) << "'s account number: ";
   cin >> tempCustomer.ID;
   cout << "Please enter customer #" << (count + 1) << "'s account balance: ";
   cin >> tempCustomer.balance;
   
   if(tempCustomer.balance < 0)
   {
      cout << "The account Balance has to be greater than 0.\n";
      cout << "Please enter a new account Balance from customer #";
      cout << (count + 1) << ": ";
      cin >> tempCustomer.balance;
   }
   return tempCustomer;
}

int editMenu(int ID)
{
    const int NAME_EDIT = 1,           //For Menu for structure edits
             ID_EDIT = 2,
             BALANCE_EDIT = 3,
             QUIT_PROGRAM = 4;
   int option; 

   cout << "You have chosen to edit Account #" << ID <<".\n";
   cout << "Your editing options are: \n";
   cout << "1:Edit the name on the account\n";
   cout << "2:Change the account ID\n";
   cout << "3:Change the balance on the account\n";
   cout << "4:Go bank to the main menu\n";
   cout << "Please enter you choice now: ";
   cin >> option;
   
   if(option < NAME_EDIT && option > QUIT_PROGRAM)
   {
      cout << "Your answer is invalid.\n";
      cout << "Your editing options are: \n";
      cout << "1:Edit the name on the account\n";
      cout << "2:Change the account ID\n";
      cout << "3:Change the balance on the account\n";
      cout << "4:Go Back to Main Menu\n";
      cout << "Please enter you choice now: ";
      cin >> option;
   }
   
   return option;
}



int main()
{
   //User Documentation 
   cout << "Welcome to the Customer Account Manager.\nIn this program, you";
   cout << " will be able to enter customer infromation,\nedit already";
   cout << " existing customer information. \nAnd print a report of the customer";
   cout << " accounts inputed during the program. \n";
   
   int numOfAccounts = 0;      //Size declarator of dynamic array
   bankAccount *customer;     //Array to be dynaically Allocated
   int option = bankMenu();   //For Menu Option
   int count;                 //Loop Counter               
   
   //Loop to keep user in program
   while(option !=4)
   {
      switch(option)
      {
         case 1:
         {
               //User Documentation
               cout << "You have chosen to input customer accounts.\n";
               cout << "You will be asked enter the number of accounts\n";
               cout << " you plan to work with today.";
               
               //Obtain the size of the array
               cout << "Please enter the number of accounts you plan to work with today: ";
               cin >> numOfAccounts;
   
             //Input Validation
             //while(numOfAccounts < 20)
//             {
//               cout << "You have to work with at least 20 accounts at a time.\nPlease";
//               cout << " enter the number of accounts you plan to work with today: ";
//               cin >> numOfAccounts;
//              }  
         
             //Dynamically Allocate Memory
               customer = new bankAccount[numOfAccounts];
               
               //User Inputs Customer information
               for(count = 0; count < numOfAccounts; count++)
               {
                  customer[count] = accountInput(count);
            
               }
               
               //Return User back to Main Menu    
               option = bankMenu();
               break;
          }
          case 2:
          {
              //User Documentation
              cout << "You have chosen to change information on an existing account.\n";
              cout << "You will be to input an account ID. If the account exisit, you\n";
              cout << "will be able to edit the specific account information and then \nwill be";
              cout << "taken back to the main menu.\n";
              
              //Declarations 
              int ID;                //For user to input account ID
              int position = -1;     //Mark position in the array when searching
              bool exist = false;    //Mark the existance of ID after search
              
              //Obtain user ID
              cout << "Please enter the account ID you wish to edit, press 4 to go back to the main menu: ";
              cin >> ID;
              
              //Search of customer array and input validation
              do{
                     
                  int count1 = 0;   //Loop Counter
                  
                  //Linear search of customer array for account ID
                  while(count1 < numOfAccounts && !exist)
                  {
                     if(customer[count1].ID == ID)
                     {
                     exist = true;
                     position = count1;
                     }
                     count1++;
                  }
                  
                  if(ID == 4)
                     exist = true;
                  
                  //Input Validation
                  if(!exist)
                  {
                     cout << "The account ID you have entered does not exist. \n";
                     cout << "Plese enter a new ID number or\n enter 4 to go back to the main menu :";
                     cin >> ID;
                  }
                  
                  
              }while(!exist);
              
              //Give user the option of going back to main menu
              if(ID == 4)
              {
               option = bankMenu();
               break;
              }
                  
              
              //Menu and switch statement to edit specific customer account
              int option1 = editMenu(ID);
                  
              switch(option1)
              {
                case 1:
                  cin.ignore();    //Input buffer eraser
                  
                  cout << "You have chosen to change the name on accout ID #" << ID << endl;
                  cout << "Please enter the new name you want to put on account ID #" << ID << ": ";
                        getline(cin, customer[position].name);
                        
                  cout << "You have successfully changed the name on the account to:" << customer[position].name;
                  cout << ".\nYou will now be taken back to the main menu.\n\n"; 
                  option = bankMenu();
                  break;
                case 2:
                  cout << "You have chosen to change the account ID for the account ID#" << ID << endl;         
                  cout << "Please enter the new account ID: ";
                  cin >> customer[position].ID;
                  
                  cout << "You have successfully changed the account ID number to: " << customer[position].ID;
                  cout << ".\nYou will now be taken back to the main menu.\n\n";
                  option = bankMenu();
                  break;
               case 3:
                  cout << "You have chosen to change the balance for account ID#" << ID << endl;
                  cout << "Please enter enter the new balance: ";
                  cin >> customer[position].balance;
                  
                  //Input Validation      
                  if(customer[position].balance < 0)
                  {
                    cout << "The balance of customer's accounts cannot be less than 0\n";
                    cout << "Please enter in a new balance for account ID#" << ID << ": ";
                    cin >> customer[position].balance;
                  }
                  
                  cout << "You have successfully changed the account balance to: " << customer[position].balance;
                  cout << ".\nYou will now be taken back to the main menu.\n\n";
                  option = bankMenu();
                  break;
               case 4:
                  cout << "You will now be taken back to the main menu. \n\n";
                  option = bankMenu();
                  break;
               }
              break; 
             }
          case 3:
          {
            cout << "\tCustomer Reports\n";
            cout << "Account ID" << "\t\t\t" << "Customer Name" << "\t\t\t" << "Account Balance" << endl;
            cout << "-----------" <<"\t\t\t" << "-------------" << "\t\t\t" << "---------------" << endl; 
            for(int count2 = 0; count2 < numOfAccounts; count2++)
            {
              cout << customer[count2].name << "\t\t" << customer[count2].ID << "\t\t" << customer[count2].balance << endl;
            }
            
            "\n\nYou will now be taken back to the main menu.";
            option = bankMenu();
            break;
          }
        }
     }
      //Option for User to quit the program
      if(option == 4)
      {
         cout << "You have chosen to quit the program.";
         if(numOfAccounts != 0)
            //Dynamically Delete memory in Array
            delete[] customer;
         return 0;
       }
          
}

