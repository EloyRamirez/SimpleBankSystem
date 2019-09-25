//+++++++++++++++++++++++++++++++++++
// Title: ConsoleApplication1.cpp
// Developer: Eloy Ramirez
// Date: 24May2019
// Description: Banking Program
//+++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

ifstream inFile;
ofstream outFile;

//++++++++++++++++++++++++++++ MAKE DEPOSIT FUNCTION ++++++++++++++++++++++++++++++++++++

void MakeDeposit()
{
	int choice;
	bool exit = 0;

	do
	{
		cout << " +----------------------------------------------+" << endl;				// In this Function, the user will be able to
		cout << " |\t\tMake A Deposit" << "\t\t\t|" << endl;								// update their balance and change the ammount
		cout << " +----------------------------------------------+" << endl;				// stored in the 'records.dat' file.
		cout << " \t\tChoice: "; cin >> choice;												// FUNCTION STILL UNFINISHED

		switch (choice)
		{
		default: cout << "\n\t\tInvalid Choice\n\n";
			system("pause");
			system("CLS");
			continue;
		case 1: system("CLS");

			break;
		case 2: system("CLS");
			exit = 1;
		}
	} while (exit == 0);

}

//++++++++++++++++++++++++++ ACCOUNT INFORMATION FUNCTION ++++++++++++++++++++++++++++++++++

void AccountInformation()
{
	int accountNumber, accountNumberInp, choice;
	double money = 1.13;	// balance placeholder
	string lastName, firstName;
	bool exit = 0;

	inFile.open("records.dat");
	inFile >> accountNumber >> firstName >> lastName;

	do
	{
		if (!inFile.fail())
		{
			cout << " +----------------------------------------------+" << endl;										// In this function, the user will have their
			cout << " |\t\t  Account Information" << "\t\t|" << endl;													// account info displayed; they will be prompted
			cout << " +----------------------------------------------+" << endl;										// to enter their account number, if the user has 
			cout << "\tEnter Account Number: "; cin >> accountNumberInp; cout << "\n";									// not made an account yet (ie. the prorgram cannot
																														// find the 'records.dat' file) before choosing the 
			// read file loop																							// 'Account Information' option, they will be prompted
																														// to create one. If they have (and the program finds
			cout << " +----------------------------------------------+" << endl;										// the file) the program will display their last name,
			cout << " |\t\t\t\t\t\t|" << endl;																			// first name, and account balance.
			cout << " |\tLast Name: " << setw(29) << left << lastName << "|" << endl;									// FUNCTION STILL UNFINISHED
			cout << " |\tFirst Name : " << setw(27) << left << firstName << "|" << endl;
			cout << " |\tAccount Balance: $" << setw(22) << left << fixed << setprecision(2) << money << "|" << endl;
			cout << " |\t\t\t\t\t\t|" << endl;
			cout << " +----------------------------------------------+" << endl;
			cout << " |\t     1. Make Deposit\t\t\t|" << endl;
			cout << " |\t     2. Make Withdrawl\t\t\t|" << endl;
			cout << " |\t     3. Exit\t\t\t\t|" << endl;
			cout << " +----------------------------------------------+" << endl;
			cout << " \t\tChoice: "; cin >> choice;

			switch (choice)
			{
			default: cout << "\n\t\tInvalid Choice\n\n";
				system("pause");
				system("CLS");
				continue;
			case 1: system("CLS");
				MakeDeposit();
				break;
			case 2: system("CLS");
				//MakeWithdrawl();
			case 3: system("CLS");
				exit = 1;
			}
		}
		else
		{
			system("CLS");
			cout << " +----------------------------------------------+" << endl;										// If user has not made an account before or program
			cout << " |\tPlease make an account first.\t\t|" << endl;													// does not find the 'records.dat' file.
			cout << " +----------------------------------------------+" << endl;
			system("pause");
			system("CLS");
			exit = 1;
		}

	} while (exit == 0);
}

//++++++++++++++++++++++++++++++++++ MAKE ACCOUNT FUNCTION +++++++++++++++++++++++++++++++++++++

void MakeAccount()
{
	int accountNumber = rand() % 99999, choice;														// Randomizer set to create a random 5 digit
	string lastName, firstName;																		// account number.
	bool exit = 0;

	outFile.open("records.dat", ios::app);															// .dat file created to store "accounts" made

	do
	{
		cout << " +----------------------------------------------+" << endl;						// In this function, the user will make their bank account;
		cout << " |\t\tMake An Account" << "\t\t\t|" << endl;										// enter first name, last name, and the
		cout << " +----------------------------------------------+" << endl;						// program will create a random account number
		cout << "\tEnter First Name: "; cin >> firstName;											// for the user. 
		cout << "\tEnter Last Name: "; cin >> lastName;
		cout << "\n\tAccount Made, Welcome!\n" << endl;
		cout << "\n\tYour Account Number Is: " << setw(5) << setfill('0') << accountNumber << endl;
		cout << " +----------------------------------------------+" << endl;
		cout << " |\t     1. Make Deposit\t\t\t|" << endl;
		cout << " |\t     2. Exit\t\t\t\t|" << endl;
		cout << " +----------------------------------------------+" << endl;
		cout << " \t\tChoice: "; cin >> choice;

		outFile << accountNumber << ' ' << firstName << " " << lastName << endl;					// First name, last name, and the account
																									// number will be stored in the 'records.dat' file
		switch (choice)
		{
		default: cout << "\n\t\tInvalid Choice\n\n";
			system("pause");
			system("CLS");
			continue;
		case 1: system("CLS");
			MakeDeposit();
			break;
		case 2: system("CLS");
			exit = 1;
		}
	} while (exit == 0);

	outFile.close();

}

//++++++++++++++++++++++++++++++++ MAIN FUNCTION +++++++++++++++++++++++++++++++++++++

int main()
{
	int mainChoice;
	bool exit = 0;

	do
	{
		cout << " +----------------------------------------------+" << endl;	// I attempted to make a menu with 3 choices:
		cout << " |\tWelcome to the First Ramirez Bank!\t|" << endl;			// Account info, make an account, and exit. Each
		cout << " |\t   How may I be of assistance?   \t|" << endl;				// choice will bring the user to another function with
		cout << " |\t\t\t\t\t\t|" << endl;										// a different menu and different choices. Each
		cout << " |\t     1. Account Information     \t|" << endl;				// menu will have an exit option wchich will take
		cout << " |\t     2. Make an account           \t|" << endl;			// the user to the previous menu.
		cout << " |\t     3. Exit\t\t\t\t|" << endl;
		cout << " +----------------------------------------------+" << endl;
		cout << " \t\tChoice: "; cin >> mainChoice;											

		switch (mainChoice)
		{
		default: cout << "\n\t\tInvalid Choice\n\n";							// The switch statement is used to go between
			system("pause");													// menus. The console clears and then prints 
			system("CLS");														// the next menu as to make the program look 
			continue;															// look cleaner and not confuse the user.
		case 1: system("CLS");
			AccountInformation();
			break;
		case 2: system("CLS");
			MakeAccount();
			break;
		case 3: system("CLS");
			exit = 1;
		}

	} while (exit == 0);														// Each menu/function is inside a do/while loop;
	cout << "\n\t Goodbye, See You Again!\n";									// the user can go back and forth between menus until
																				// the user chooses the final 'exit' that ends the loop.
	inFile.close();

	return 0;
}

