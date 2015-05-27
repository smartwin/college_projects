// Assignment #3: Bill Calculation
// This program will calculate a customer's
// monthly bill based on the package they 
// purchaed and the hours of access they used.

#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
   //Declarations
   char package;          //to hold cusotmer's package choice
   int hours;             //to hold the hours accessed for packages A and B;
   double bill;           //to hold the value of monthly bill;
   
   //constants for package options
   const char A_CHOICE = 'A',
              B_CHOICE = 'B',
              C_CHOICE = 'C',
              QUIT_CHOICE = 'Q';
   
   //constants for package rates
   const double A = 9.95,
                B = 14.95,
                C = 19.95;    
   
   //User Documentation
   cout << "This program will calucate your"
        << " monthly bill based on the package"
        << " you purchased.\nIf you chose packages"
        << " A or B, the extra hours accessed will also be used"
        << " to calculate your monthly bill.\n" << endl;
   
   //Loop to keep user in options menu
   while(package != QUIT_CHOICE)
   {
      //Display the customer's packeage options
      cout << "\t\tInternet Service Packages\n\n"
           << "Package A: For $9.95 per month 10 hours of access provided. Additional hours are $2.00 per hour.\n"
           << "Package B: For $14.05 per month 20 hours of access provided. Additional hours are $1.25 per hour.\n"
           << "Package C: For $19.95 per month unilimited access is provided.\n"
           << "Quit: Cancel the program.\n\n"
           << "Enter your choice (Please only use capital letters): ";
      cin >> package; 
   
      //Format the output for user's monthly bill
      cout << fixed << setprecision(2)	<<	showpoint; 
	
   	//Respond to customer's	package choice
   	switch (package)
   	{
   		case A_CHOICE:
            //Obtain the number of hours from user
   			cout << "For how many hours do you plan to use this service?: ";
   			cin >> hours;
            //Loop to determine the monthly bill
   			if(hours	<=	744)
   			{  
               //Nested Loop to account for hours greater than package hours
   				if(hours	> 10)
   				{
   					bill = A	+ (2 * (hours-10));
   					cout << "The monthly bill will be: $" << bill << "\n"; 
   				}
   				else
   				{
   					bill = A;
   					cout << "The monthly bill will be: $" << bill << "\n"; 
   				}
   			}
   			else 
   				cout << "Your hours cannot exceed 744 hours";
   			break;
   		
   		case B_CHOICE:
            //Obtain hours
   			cout << "For how many hours?: ";
   			cin >> hours;
            
            //Loop to calculate bill
   			if(hours	<=744)
   			{
               //Nested loop to account for hours greater than alloted package hours
   				if(hours	> 20)
   				{
   					bill = B	+ (1.25 * (hours-20));
   					cout << "The monthly bill will be: $" << bill << "\n"; 
   				}
   				else
   				{
   					bill = B;
   					cout << "The monthly bill will be: $" << bill << "\n"; 
   				}
   			}
   			else
   				cout << "Your hours cannot exceed 744 hours";
   			break;
   		
   		case C_CHOICE:
   			
            bill = C;
   			cout << "The monthly bill will be: $" << bill << "\n"; 
   			break;
   		
   		case QUIT_CHOICE:
   			cout << "You have chosen not to purchase an internet package.";
   			break;
   		
   		default:	
   			cout << "The valid choices are A, B, C, and Q.";
   	}
    }
}
   
