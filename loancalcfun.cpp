/***************************************************
 * Program:loanCalculator.c
 * Author: Joel Salisbury
 * Date: February 1, 2014
 * Due Date: February 11, 2014
 * Lab: #2
 * Description: 
 * 	Asks the user to input 
 *		1.Loan Amount
 *		2. Monthly Payment
 *		3. Interest Rate  - must clearly tell user proper format (.1 || 10)
 *
 *	Calculates 
 *		1. Monthly Interest Rate  	= Interest Rate divided by 12 
 *		2. Minimum Interest Payment = the monthly interest rate multiplied by the principle.
 *			if the minimum interest payment is greater than the monthly returns error message and asks for a new value		
 *		
 *	While the Principle amount is greater than the monthly payment 
 *		1. calculates the amount of the principle that will be paid for each loan payment based on the monthly 
 *			payment the user enters
 *		2. calculates the new interest payment amount for the next payment based on the new principle amount.
 *		3. Prints out payment number  Balance left to be payed Payment Amount Interest Payed and Principle 
 *	left to be payed after the payment is applied
 *	once the amortization table is printed user is given a summary of amount of interest payed. 
 *	Total Interest Payed, Annualized Interest and the percent of Amortized Interest.
 */
#include <iostream>
#include <iomanip>

using namespace std;

const double MONTHS=12;

double getLoanAmount();

double getPaymentAmount();

void intro();

double getLoanAmount();

double getInterestRate();

double getPaymentAmount(double interestPayment);

int calculateMonths(double principle,double interestRate, double monthlyPayment);

void displayResults(int month, double principle, double monthlyPayment, double interestPayment, double principlePayment, double totalInterest);

int main(){
	double loanAmount=0;
	double monthlyPayment=0;
	double interestPayment=0; 
	double interestRate=0;
	double monthlyInterest=0;
	double principle=0;
	double principlePayment=0;
	double nextPrinciple=0;
	double totalInterest=0;
	double percentInterest=0;
	int months=0;


	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	

	intro();

	principle = getLoanAmount();
	interestRate=getInterestRate();
	monthlyInterest = interestRate/MONTHS;
	interestPayment = (principle*monthlyInterest);
	monthlyPayment = getPaymentAmount(interestPayment);
	cout << monthlyPayment << "\n";
	months=calculateMonths(principle, interestRate, monthlyPayment);

}

	void intro(){
		cout << "This Program will calculate the number of payments and the amount of interest paid";  
		cout <<" over the life of a loan. based on the Amount of the loan,"; 
		cout << " interest rate and the monthly payment amount.";
		}

	double getLoanAmount(){
			double loanAmount;
			cout << "Enter Loan Amount\n Formatted as 1000.00 exclude a dollar sign from entry\n";
			cin >> loanAmount;
			return loanAmount;
		}

	double getInterestRate(){

			double interestRate=0;
			cout << "Enter Interest Rate\n Formatted as 10.00 you may include a percent sign\n";
			cin >> interestRate;
			interestRate=((interestRate))/100.0;
		return interestRate;
	}

	double getPaymentAmount(double interestPayment){

		double monthlyPayment=0;
		do{
			cout << "Enter your Monthly Payment Amount\n Formatted as 1000.00 exclude a dollar sign from entry\n";
			cin >> monthlyPayment;

			if(monthlyPayment<interestPayment)
				cout << "Enter a value Sufficent to cover the monthly interest payment"; 
			}while(monthlyPayment<interestPayment);
		return monthlyPayment;
	}
	int calculateMonths(double principle,double interestRate, double monthlyPayment){
		
			cout << setw(5) << "Month" << setw(15) << "Balance";
			cout << setw(15) << "Monthly Payment" << setw(15) << "Interest" << setw(15) << "Principle\n";
			double monthlyInterest=interestRate/MONTHS;
			double interestPayment =  principle*monthlyInterest;
			double principlePayment=monthlyPayment-interestPayment;
			double nextPrinciple=principle-principlePayment;
			double totalInterest=interestPayment;
			int month=0;

			double loanAmount;	

		cout << principle << "\n";
		cout << monthlyPayment;

		while(principle>=monthlyPayment){
		
		/**
		 * Print values for each month
		 */

		
		displayResults(month, principle, monthlyPayment, interestPayment, principlePayment, totalInterest);

		principle=nextPrinciple;
		interestPayment=principle*monthlyInterest;
		totalInterest+=interestPayment;
		principlePayment=monthlyPayment-interestPayment;
		nextPrinciple=principle-principlePayment;
		month++;
		}
		displayResults(month, principle, monthlyPayment, interestPayment, principlePayment, totalInterest);
		return month;
	}

	void displayResults(int month,double principle,double monthlyPayment,double interestPayment,double principlePayment,double totalInterest){

		double annualizedInterest=0;
		double percentInterest=0;


		if (month<1){
			cout << setw(5) << "Month" << setw(15) << "Balance";
			cout << setw(15) << "Monthly Payment" << setw(15) << "Interest" << setw(15) << "Principle\n";
		}else{if (principle>=monthlyPayment){
		cout << setw(5) << month << setw(15) << principle;
		cout << setw(15) << monthlyPayment << setw(15) << interestPayment << setw(15) << principlePayment <<"\n";
		}else{
		/** 
		 *	set all values for next iteration
		 */

		
		

		annualizedInterest=totalInterest/(month/MONTHS);
		

		percentInterest=annualizedInterest/principle*100;

		/*
		 * Output values for final payment
		 */
 		cout << setw(5) << month << setw(15) << principle;
		cout << setw(15) << principle+interestPayment << setw(15) << interestPayment << setw(15) << principle <<"\n";
		cout << setw(55) << "Number of Months to Payoff the Loan:" << setw(20) << month  << "\n";
		cout << setw(55) << "Total Interest:" << setprecision(2) << setw(20) <<totalInterest << endl;
		cout << setw(55) << "Annualized Interest:" << setw(20) <<annualizedInterest  << "\n";
		cout << setw(55) << "Percent of Annualized Interest from the Total Loan:" << setprecision(2) << setw(20) <<percentInterest << "\%"<< endl;
		}
		}
	}


		
	


	
			

	



