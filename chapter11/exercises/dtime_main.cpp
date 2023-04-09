/**
 * @file dtime_main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "dtime.cpp"

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    vector<DTime> dtime_vector;
    DTime dtime;
    int hours;
    int minutes;
    int seconds;
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
        dtime.setHours(hours);
        dtime.setMinutes(minutes);
        dtime.setSeconds(seconds);
        dtime_vector.push_back(dtime);
    }
    for(int i = 0; i < dtime_vector.size(); i++)
    {
        cout << dtime_vector[i].getHours() << ":" << dtime_vector[i].getMinutes() << ":" << dtime_vector[i].getSeconds() << endl;
    }
    return 0;
}
