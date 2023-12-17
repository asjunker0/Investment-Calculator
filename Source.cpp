/*
Abbigale Junker
CS-210
Project 2
Eric Gregori
11/26/2023
*/

#include <iostream>
#include <iomanip>	// Allows for table organization and float manipulation
using namespace std;

// Turning functions into class methods follows OOP structure (more than what I did before rereading the rubric)
class InvestmentCalculator {
public:

	//	Reduces repetition of code
	void printDataInput(int path, float initialInvestment, float monthlyDeposit, float annualInterest, int years) {
		cout << "**********************************" << endl;
		cout << "*********** Data Input ***********" << endl;

		if (path == 1) {
			cout << "Initial Investment Amount: $";
		}
		else if (path == 2) {
			cout << "Initial Investment Amount: $" << initialInvestment << endl;
			cout << "Monthly Deposit: $";
		}
		else if (path == 3) {
			cout << "Initial Investment Amount: $" << initialInvestment << endl;
			cout << "Monthly Deposit: $" << monthlyDeposit << endl;
			cout << "Annual Interest: %";
		}
		else if (path == 4) {
			cout << "Initial Investment Amount: $" << initialInvestment << endl;
			cout << "Monthly Deposit: $" << monthlyDeposit << endl;
			cout << "Annual Interest: %" << annualInterest << endl;
			cout << "Number of Years: ";
		}
	}

	void printReportNoMonthlyDeposits(float initialInvestment, float annualInterest, int years) {

		// Report title and categories
		cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
		cout << "==================================================================" << endl;
		cout << right << setw(5) << "Year" << setw(25) << "Year End Balance ($)" << setw(35) << "Year End Earned Interest ($)" << endl;
		cout << "------------------------------------------------------------------" << endl;

		// Values used in method
		float interest;
		float endBalance = initialInvestment;

		for  (int i = 0;  i < years; i++){
			interest = endBalance * (annualInterest / 100); // Calculates yearly interest
			endBalance += interest;	// Calculates year end balance

			cout << right << setw(5) << i + 1 << setw(25) << fixed << setprecision(2) << endBalance << setw(35) << fixed << setprecision(2) << interest << endl; // Prints and aligns values in one line
		}
		cout << "==================================================================" << endl << endl;
	}

	void printReportMonthlyDeposits(float initialInvestment, float monthlyDeposit, float annualInterest, int years) {

	// Report title and categories
	cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
	cout << "==================================================================" << endl;
	cout << right << setw(5) << "Year" << setw(25) << "Year End Balance ($)" << setw(35) << "Year End Earned Interest ($)" << endl;
	cout << "------------------------------------------------------------------" << endl;

	// Values used in method
	float interest;
	float endBalance = initialInvestment;
	float monthlyInt;

	for (int i = 0; i < years; i++) {
		interest = 0;	// Resets interest value for loop
		for (int j = 0; j < 12; j++){ // loops 12 times to calculate each month
			monthlyInt = (endBalance + monthlyDeposit) * ((annualInterest/100)/12); // Calculates monthly interest
			endBalance += monthlyDeposit + monthlyInt;	// Calculates year end balance
			interest += monthlyInt; // Calculates annual interest
		}
		
		// Prints and aligns values AND limits floats to two decimals
		cout << right << setw(5) << (i + 1);
		cout << right << setw(25) << fixed << setprecision(2) << endBalance;
		cout << right << setw(35) << fixed << setprecision(2) << interest << endl;
	}
	cout << "==================================================================" << endl << endl;
}
};

int main() {

	// Variables that are initialized
	float initialInvestment = -1;
	float monthlyDeposit = -1;
	float annualInterest = -1;
	int years = -1;
	InvestmentCalculator calc;

	calc.printDataInput(0, initialInvestment, monthlyDeposit, annualInterest, years); // initial Data Input screen
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of Years:" << endl;
	cout << "Press the Enter key to continue . . ." << endl;

	cin.ignore();  // Ignore the key press

	// The following code validates user input for each variable

	calc.printDataInput(1, initialInvestment, monthlyDeposit, annualInterest, years);
	while (!(cin >> initialInvestment)){	// while input is invalid prompt user for valid input, validates user input
		cin.clear();	// clear input buffer to restore cin to a usable state
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ignores previous input
		cout << endl << "Invalid input. Please enter a valid number." << endl << endl;

		calc.printDataInput(1, initialInvestment, monthlyDeposit, annualInterest, years);
	}

	// Prompts user for monthly deposit
	cout << "Monthly Deposit: $";
	while (!(cin >> monthlyDeposit)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please enter a valid number." << endl << endl;

		calc.printDataInput(2, initialInvestment, monthlyDeposit, annualInterest, years);
	}

	// Prompts user for annual interest
	cout << "Annual Interest: %";
	while (!(cin >> annualInterest)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please enter a valid number." << endl << endl;

		calc.printDataInput(3, initialInvestment, monthlyDeposit, annualInterest, years);
	}

	// Prompts user for numer of years
	cout << "Number of Years: ";
	while (!(cin >> years)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl << "Invalid input. Please enter a valid number." << endl << endl;

		calc.printDataInput(4, initialInvestment, monthlyDeposit, annualInterest, years);
	}

	cout << "Press the Enter key to continue . . ." << endl;
	cin.ignore();  // Ignore the key press
	cin.ignore();

	// Calls methods to print each report
	calc.printReportNoMonthlyDeposits(initialInvestment, annualInterest, years);
	calc.printReportMonthlyDeposits(initialInvestment, monthlyDeposit, annualInterest, years);

	return 0;

}