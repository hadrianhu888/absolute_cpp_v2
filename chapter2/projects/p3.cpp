/**
 * @file p3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath> 

using namespace std; 

void returnTotalChocolateBarsGivenCoupons(int totalChocolateBars, int StartingAmount, int RedemptionAmount); 

void returnTotalChocolateBarsGivenCoupons(int totalChocolateBars, int StartingAmount, int RedemptionAmount) {
    int newChocolateBars = 0; 
    int additionalChocolateBars = 0; 
    if ((StartingAmount / RedemptionAmount) + StartingAmount > RedemptionAmount) {
        newChocolateBars = StartingAmount / RedemptionAmount; 
        cout << "New Chocholate Bars available: " << newChocolateBars << endl; 
        additionalChocolateBars = (totalChocolateBars % RedemptionAmount) + newChocolateBars; 
        cout << "The total amount of chocolate bars available are: " << totalChocolateBars << endl; 
        //returnTotalChocolateBarsGivenCoupons(totalChocolateBars, StartingAmount, RedemptionAmount); 
    } else {
        cout << "Sorry, you only have " << StartingAmount << " of chocolate bars available, since you need at least " << RedemptionAmount << " to get more chocolate bars." << endl; 
    }
    totalChocolateBars = totalChocolateBars + additionalChocolateBars; 
    cout << "The total amount of chocolate bars is: " << totalChocolateBars << endl; 
}

int main(int argc, char ** argv) {

    int redeemAount = 0; 
    int Amount = 0; 
    int totalChocolateBars = 0; 
    int newChocolateBarsAfterRedemption = 0; 

    /**
     * @brief get inputs 
     * 
     */
    cout << "Enter the amount of money: "; 
    cin >> Amount; 
    cout << endl << "Enter the redeem amount to get another chocolate bar: "; 
    cin >> redeemAount;   
    totalChocolateBars = Amount; 
    cout << "The total amount of initial chocolate bars and redemption coupons are: " << Amount << endl; 
    /**
     * @brief 
     * 
     */
    returnTotalChocolateBarsGivenCoupons(totalChocolateBars, Amount, redeemAount); 
    return 0; 
}
