/*

PointBreak Surf Shop Program
By Justin Smith
ITCS 2530 V0801

This program allows the surf shop to enter purchases, track total purchases, and show
the total purchase amounts for the duration of the program as long as it is ran. The user
may choose to end the program when he/she chooses.

This program has been modified to include the addition of a new surfboard, size XXXS, that is 
used for squirrel surfing. The cost of this new sufboard is $35.00.

*/

#include <iostream> // I/O header file 
#include <iomanip> // Header for format manipulation
#include <string> // Need for using string type

using namespace std;

// Named constants
const double XXXS_PRICE = 35.00;
const double SMALL_PRICE = 175.00;
const double MEDIUM_PRICE = 190.00;
const double LARGE_PRICE = 200.00;


// For reference, program begins with main function at line 160


// Function to further describe the options available to the user
void ShowUsage()
{
	cout << endl << endl;
	cout << "This program calculates your current purchase" << endl << endl;
	cout << "The purchase option allows you to enter the desired amount of a type of surfboard" << endl;
	cout << "To use this option, enter 'P'. You may return and enter other items at any time." << endl << endl;

	cout << "The display current purchases option shows you the totals so far for the transaction" << endl;
	cout << "To use this option, enter 'C'. You may check these at any time as well." << endl << endl;

	cout << "The display total displays the totals for each type of board and the total for the transaction" << endl;
	cout << "To use this option, enter 'T'." << endl << endl;

	cout << "Simply enter 'Q' to terminate the transaction at any time." << endl << endl;

	return;
}


// Function to sell surfboards, takes input of quantities and size, and adds them to the appropriate by reference variable
void MakePurchase(int& iTotalXXXSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
	// Declare local variables to MakePurchase function. These are used to hold purchase information
	int purchaseQuantity;
	string purchaseType;

	cout << "Please enter the quanity and type(XXXS=3x small, S=small, M=medium, L=large) of surfboard you "
		<< "would like to purchase : ";
	cin >> purchaseQuantity >> purchaseType;

	// if / else structure that looks for the appropriate type entered
	 if (purchaseType == "XXXS" || purchaseType == "xxxs")
	{
		iTotalXXXSmall += purchaseQuantity; // increment the reference variable iTotalSmall if purchased
		return;
	}
	else if (purchaseType == "S" || purchaseType == "s")
	{
		iTotalSmall += purchaseQuantity; // increment the reference variable iTotalSmall if purchased
		return;
	}
	else if (purchaseType == "M" || purchaseType == "m")
	{
		iTotalMedium += purchaseQuantity; // increment the reference variable iTotalMedium if purchased
		return;
	}
	else if (purchaseType == "L" || purchaseType == "l")
	{
		iTotalLarge += purchaseQuantity; // increment the reference variable iTotalLarge if purchased
		return;
	}
	else
		return; // Returns to menu, user did not want to enter purchase information
}


// This function shows the totals for boards that have sales
void DisplayPurchase(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	// Following code outputs the totals for each surfboard if there are sales on it
	if (iTotalXXXSmall > 0)
		cout << "The total number of extra extra extra small surfboards is " << iTotalXXXSmall << endl;
	if (iTotalSmall > 0)
		cout << "The total number of small surfboards is " << iTotalSmall << endl;
	if (iTotalMedium > 0)
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;
	if (iTotalLarge > 0)
		cout << "The total number of large surfboards is " << iTotalLarge << endl;
	// If no sales found by if else statement below, output no purchases made
	if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
		cout << "No purchases made yet." << endl;
	return;
}


// This function shows the total amount of money made for the current execution of this program 
void DisplayTotal(const int iTotalXXXSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	double total3xSmallPrice = 0.00;
	double totalSmallPrice = 0.00;
	double totalMediumPrice = 0.00;
	double totalLargePrice = 0.00;

	// If no sales found by if else statement below, output no purchases made and return to main
	if (iTotalXXXSmall == 0 && iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0)
	{
		cout << "No purchases made yet." << endl;
		return;
	}
		
	// If there is a quantity for any sizes, output the total for that size
	if (iTotalXXXSmall > 0)
	{
		total3xSmallPrice = iTotalXXXSmall * XXXS_PRICE;
		cout << "The total number of extra extra extra small surfboards is " << iTotalXXXSmall 
			<< " at a total of $" << fixed << setprecision(2) << total3xSmallPrice << endl;
	}
	if (iTotalSmall > 0)
	{
		totalSmallPrice = iTotalSmall * SMALL_PRICE;
		cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $"
			<< fixed << setprecision(2) << totalSmallPrice << endl;
	}
	if (iTotalMedium > 0)
	{
		totalMediumPrice = iTotalMedium * MEDIUM_PRICE;
		cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $"
			<< fixed << setprecision(2) << totalMediumPrice << endl;
	}
	if (iTotalLarge > 0)
	{
		totalLargePrice = iTotalLarge * LARGE_PRICE;
		cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $"
			<< fixed << setprecision(2) << totalLargePrice << endl;
	}

	// Output total for all surf boards combined 
	cout << "Amount Due: $" << fixed << setprecision(2) << total3xSmallPrice + totalSmallPrice + totalMediumPrice + totalLargePrice << endl;

}


// ************************************************************************************** \\
// ++++++++++++++++++++++++++++++++++++++++  MAIN  +++++++++++++++++++++++++++++++++++++* \\
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**+ \\


int main()
{
	// Declare and/or initialize variables 
	char userPrompt;
	int xxxsmallBoardsSold = 0;
	int smallBoardsSold = 0;
	int mediumBoardsSold = 0;
	int largeBoardsSold = 0;

	// Program header
	cout << setw(62) << left << setfill('*') << "*" << endl;
	cout << setw(5) << left << setfill('*') << "*";
	cout << "  Welcome to my Johnny Utah's PointBreak Surf Shop  ";
	cout << setw(5) << right << setfill('*') << "*" << endl;
	cout << setw(62) << left << setfill('*') << "*" << endl << endl << endl;

	// Program menu
	cout << "To show program usage 'S'" << endl; // refer to ShowUsage function
	cout << "To purchase a surfboard press 'P'" << endl; // refer to function MakePurchase
	cout << "To display current purchases press 'C'" << endl; // refer to the DisplayPurchase function
	cout << "To display total amount due press 'T'" << endl; // refer to the DisplayTotal function
	cout << "To quit the program press 'Q'" << endl << endl; // Terminates the program
	cout << "Please enter selection: ";
	cin >> userPrompt; //*****Need to research changing char to upper...Or use string********

	// I use pretest while loop here becuase I do not know the number of iterations to this loop
	// Loop terminates when Q is entered
	while (userPrompt != 'Q' && userPrompt != 'q')
	{
		if (userPrompt == 'S' || userPrompt == 's')
			ShowUsage();
		else if (userPrompt == 'P' || userPrompt == 'p')
			MakePurchase(xxxsmallBoardsSold, smallBoardsSold, mediumBoardsSold, largeBoardsSold);
		else if (userPrompt == 'C' || userPrompt == 'c')
			DisplayPurchase(xxxsmallBoardsSold, smallBoardsSold, mediumBoardsSold, largeBoardsSold);
		else if (userPrompt == 'T' || userPrompt == 't')
			DisplayTotal(xxxsmallBoardsSold, smallBoardsSold, mediumBoardsSold, largeBoardsSold);

		cout << endl;
		cout << "Please enter selection: ";
		cin >> userPrompt;
	}

	cout << "Thank you" << endl;

	system("pause");

	return 1;
}
