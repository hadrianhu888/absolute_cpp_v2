/**
 * @file p5.cpp
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

int main(int argc, char ** argv) {
    /**
     * @brief 
     * 
     */
    int MaxPeopleInRoom = 0; 
    int ActualNumberInRoom = 0; 
    int MaxAllowablePeople = 0; 
    int MaxPeopleExceeded = 0; 
    cout << "Enter how many people are allowed in the room: "; 
    cin >> MaxPeopleInRoom; 
    cout << endl << "Enter the actual people in the room: "; 
    cin >> ActualNumberInRoom; 
    if (ActualNumberInRoom > MaxPeopleInRoom) {
        MaxPeopleExceeded = ActualNumberInRoom - MaxPeopleInRoom; 
        cout << "The room must remove at least " << MaxPeopleExceeded << " to meet fire safety requirements.\n\n\n";
    } else if (ActualNumberInRoom < MaxPeopleInRoom) {
        MaxAllowablePeople = MaxPeopleInRoom - ActualNumberInRoom; 
        cout << "The room can still allow for a maximum of " << MaxAllowablePeople << " into the room.\n\n\n"; 
    }
    return 0;
}





