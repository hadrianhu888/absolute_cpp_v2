//Daniel Nestor
//Period 1B
//students will Create a program that will display a table the amortization for the following loans:



// This program produces a loan amortization table for the
// Central Mountain Credit Union. It is an updated version 
// of Program 5-18, corrected to handle a zero interest loan.
#include <iostream>
#include <iomanip>
#include <cmath>          // Needed for the pow function
using namespace std;

int main()
{
	double loan,			// Loan amount
		   rate,            // Annual interest rate
		   moInterestRate,  // Monthly interest rate
		   years,           // Years of loan
		   balance,         // Monthly balance
		   term,            // Used to calculate payment
		   payment;         // Monthly payment
    int numPayments;     // Number of payments
    years = 25;
    loan = 499000;
    rate = .15;

        
    cout << "Loan amount: $" << fixed << loan << endl; 
    cout << "Annual interest rate (entered as a decimal): " << rate * 100 << endl; 
    cout << "Years of loan: " << years << endl; 

	// Calculate monthly payment
	// A zero interest loan must be handled as a special case to avoid
	// a divide by 0 in the payment formula used for loans with interest.
	numPayments = static_cast<int>(12 * years);
	moInterestRate = rate / 12.0;
	if (rate == 0)
		payment = loan / numPayments;
	else
        {	
            term = pow((1 + moInterestRate), numPayments);
            payment = (loan * moInterestRate * term) / (term - 1.0);
        }
   
	// Display monthly payment
    cout << fixed << showpoint << setprecision(2);
    cout << "Monthly payment: $" << payment << endl;

	// Display report header
    cout << endl;
    cout << setw(5)  << "Month"     << setw(10) << "Interest";
    cout << setw(10) << "Principal" << setw(9)  << "Balance" << endl;
    cout << "----------------------------------\n";

    balance = loan;       // Remaining balance starts out as full loan amount

	// Produce a listing for each month
	for (int month = 1; month <= numPayments; month++)
	{
		double moInterest,          // Amount of pmt that pays interest
               principal;           // Amount of pmt that lowers the balance

		// Calculate amount paid for this month's interest and principal
		moInterest = moInterestRate * balance;  // Calculate interest first
		if (month != numPayments)               // If not the final month
			principal = payment - moInterest;   // rest of pmt goes to principal

		else	                                // It's the last month so
		{	principal = balance;                // pay exact final balance
        payment = balance + moInterest;
		}
		// Calculate new loan balance           // Only principal reduces the
        balance -= principal;                   // balance, not the whole pmt

		// Display this month's payment figures
        cout << setw(4)  << month     << setw(10) << moInterest;
        cout << setw(10) << principal << setw(10) << balance << endl;			
	}
	return 0;
}