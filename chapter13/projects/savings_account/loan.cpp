/**
 * @file loan.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;
double get_remaining_principal(double principal,
                               double payment,
                               double interestRatePerPeriod,
                               int currentPeriod,
                               int paymentPeriodsPerYear);
void generate_amortization_table(double remainingPrincipal,
                                 double payment,
                                 double interestRatePerPeriod,
                                 int currentPeriod,
                                 int totalPayments,
                                 int paymentPeriodsPerYear,
                                 ostream &out);
void save_to_file(double principal,
                  double annualInterestRate,
                  double period,
                  const string &periodUnit,
                  int compoundFrequency,
                  const string &paymentPeriod,
                  double payment,
                  int paymentPeriodsPerYear,
                  int totalPayments,
                  double interestRatePerPeriod);

int main()
{
    double principal, annualInterestRate, period;
    int compoundFrequency;
    string periodUnit, paymentPeriod;

    cout << "Enter the principal amount: ";
    cin >> principal;

    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> annualInterestRate;
    annualInterestRate /= 100;

    cout << "Enter the period: ";
    cin >> period;

    cout << "Enter the period unit (days, weeks, months, years): ";
    cin >> periodUnit;

    cout << "Enter the compound frequency (number of times interest is compounded per year): ";
    cin >> compoundFrequency;

    cout << "Enter the payment period (daily, weekly, monthly, yearly): ";
    cin >> paymentPeriod;

    int paymentPeriodsPerYear;
    if (paymentPeriod == "daily")
    {
        paymentPeriodsPerYear = 365;
    }
    else if (paymentPeriod == "weekly")
    {
        paymentPeriodsPerYear = 52;
    }
    else if (paymentPeriod == "monthly")
    {
        paymentPeriodsPerYear = 12;
    }
    else if (paymentPeriod == "yearly")
    {
        paymentPeriodsPerYear = 1;
    }
    else
    {
        cout << "Invalid payment period" << endl;
        return 1;
    }

    if (periodUnit == "days")
    {
        period /= 365;
    }
    else if (periodUnit == "weeks")
    {
        period /= 52;
    }
    else if (periodUnit == "months")
    {
    period /= 12;
    }

    double interestRatePerPeriod = pow(1 + annualInterestRate / compoundFrequency,
                                        compoundFrequency / static_cast<double>(paymentPeriodsPerYear)) -
                                    1;
    int totalPayments = static_cast<int>(period * paymentPeriodsPerYear);
    double payment = principal * (interestRatePerPeriod * pow(1 + interestRatePerPeriod, totalPayments)) /
                        (pow(1 + interestRatePerPeriod, totalPayments) - 1);

    cout << "---------------------------------------------" << endl;
    cout << "Period\tInterest\tPrincipal Remaining" << endl;
    generate_amortization_table(principal, payment, interestRatePerPeriod, 1, totalPayments, paymentPeriodsPerYear, cout);

    save_to_file(principal,
                 annualInterestRate * 100,
                 period,
                 periodUnit,
                 compoundFrequency,
                 paymentPeriod,
                 payment,
                 paymentPeriodsPerYear,
                 totalPayments,
                 interestRatePerPeriod);

    return 0;
}

double get_remaining_principal(double principal,
                                   double payment,
                                   double interestRatePerPeriod,
                                   int currentPeriod,
                                   int paymentPeriodsPerYear)
{
    if (currentPeriod == 1)
    {
        return principal;
    }
    double previousRemainingPrincipal = get_remaining_principal(principal,
                                                                payment,
                                                                interestRatePerPeriod,
                                                                currentPeriod - 1,
                                                                paymentPeriodsPerYear);
    double interestPayment = previousRemainingPrincipal * interestRatePerPeriod;
    double principalPayment = payment - interestPayment;
    return previousRemainingPrincipal - principalPayment;
}


void generate_amortization_table(double remainingPrincipal,
                                 double payment,
                                 double interestRatePerPeriod,
                                 int currentPeriod,
                                 int totalPayments,
                                 int paymentPeriodsPerYear,
                                 ostream &out)
{
    if (currentPeriod > totalPayments)
    {
        return;
    }

    double interestPayment = remainingPrincipal * interestRatePerPeriod;
    double principalPayment = payment - interestPayment;
    double newRemainingPrincipal = remainingPrincipal - principalPayment;

    out << currentPeriod << "\t\t" << fixed << setprecision(6) << interestPayment << "\t\t" << newRemainingPrincipal
        << endl;

    generate_amortization_table(newRemainingPrincipal,
                                payment,
                                interestRatePerPeriod,
                                currentPeriod + 1,
                                totalPayments,
                                paymentPeriodsPerYear,
                                out);
}

void save_to_file(double principal,double annualInterestRate,double period,const string &periodUnit,int compoundFrequency,const string &paymentPeriod,double payment,int paymentPeriodsPerYear,int totalPayments,double interestRatePerPeriod)
{
    time_t currentTime = time(0);
    tm *localTime = localtime(&currentTime);
    char filename[50];
    strftime(filename, 50, "amortization_table_%Y_%m_%d_%H_%M_%S.txt", localTime);

    ofstream file(filename);

    if (!file)
    {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    // ... (same as before, writing data to the file)

    file.close();
    cout << "Amortization table saved to " << filename << endl;
}
