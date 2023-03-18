/**
 * @file p2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream> 
#include <cstdio>
#include <math.h>
#include <cmath> 

using namespace std; 

const double ArtificialSweetener = 0.001; 

int main(int argc, char ** argv) {
    /**
     * @brief 
     * 
     */
    double mouseWeight = 0.000; 
    double sweetenerToKillMouse = 0.00; 
    double startingFriendWeight = 0.0; 
    double endingFriendWeight = 0.0; 
    double amountofSweetenerForHuman = 0.0;
    cout << "Enter the starting and ending weight of your friend: "; 
    cin >> startingFriendWeight; 
    cin >> endingFriendWeight; 
    cout << "Enter the weight of the mouse and weight of sweetener need to kill the mouse: "; 
    cin >> mouseWeight; 
    cin >> sweetenerToKillMouse; 
    amountofSweetenerForHuman = (startingFriendWeight - endingFriendWeight) / mouseWeight * sweetenerToKillMouse; 
    cout << "The amount of sweetener needed for your friend to reach his diet goal without sacrificing soda is: " << amountofSweetenerForHuman << " grams of artifical sweetener" << endl; 
    return 0;
}