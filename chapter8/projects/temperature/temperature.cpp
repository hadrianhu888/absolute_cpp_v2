/**
 * @file temperature.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

class Temperature
{
    private:
        double temp;
        char scale;
        void set_temp(double temp);
        void set_scale(char scale);
        double get_temp();
        char get_scale();
    public:
        Temperature();
        Temperature(double temp, char scale);
        Temperature(double temp);
        Temperature(char scale);
        void set(double temp, char scale);
        void set(double temp);
        void set(char scale);
        double get_fahrenheit();
        double get_celsius();
        double get_kelvin();
        friend Temperature operator+(Temperature t1, Temperature t2);
        friend Temperature operator-(Temperature t1, Temperature t2);
        friend Temperature operator*(Temperature t1, Temperature t2);
        friend Temperature operator/(Temperature t1, Temperature t2);
        friend bool operator==(Temperature t1, Temperature t2);
        friend bool operator!=(Temperature t1, Temperature t2);
        friend bool operator<(Temperature t1, Temperature t2);
        friend bool operator<=(Temperature t1, Temperature t2);
        friend bool operator>(Temperature t1, Temperature t2);
        friend bool operator>=(Temperature t1, Temperature t2);
        friend ostream& operator<<(ostream& out, Temperature t);
        friend istream& operator>>(istream& in, Temperature& t);
};

Temperature::Temperature()
{
    temp = 0;
    scale = 'C';
}

Temperature::Temperature(double temp, char scale)
{
    this->temp = temp;
    this->scale = scale;
}

Temperature::Temperature(double temp)
{
    this->temp = temp;
    scale = 'C';
}

Temperature::Temperature(char scale)
{
    temp = 0;
    this->scale = scale;
}

void Temperature::set(double temp, char scale)
{
    this->temp = temp;
    this->scale = scale;
}

void Temperature::set(double temp)
{
    this->temp = temp;
}

void Temperature::set(char scale)
{
    this->scale = scale;
}

double Temperature::get_fahrenheit()
{
    if (scale == 'C')
    {
        return (temp * 9 / 5) + 32;
    }
    else if (scale == 'K')
    {
        return (temp - 273.15) * 9 / 5 + 32;
    }
    else
    {
        return temp;
    }
}

double Temperature::get_celsius()
{
    if (scale == 'F')
    {
        return (temp - 32) * 5 / 9;
    }
    else if (scale == 'K')
    {
        return temp - 273.15;
    }
    else
    {
        return temp;
    }
}

double Temperature::get_kelvin()
{
    if (scale == 'F')
    {
        return (temp - 32) * 5 / 9 + 273.15;
    }
    else if (scale == 'C')
    {
        return temp + 273.15;
    }
    else
    {
        return temp;
    }
}

Temperature operator+(Temperature t1, Temperature t2)
{
    Temperature t;
    t.set_temp(t1.get_temp() + t2.get_temp());
    t.set_scale(t1.get_scale());
    return t;
}

Temperature operator-(Temperature t1, Temperature t2)
{
    Temperature t;
    t.set_temp(t1.get_temp() - t2.get_temp());
    t.set_scale(t1.get_scale());
    return t;
}

Temperature operator*(Temperature t1, Temperature t2)
{
    Temperature t;
    t.set_temp(t1.get_temp() * t2.get_temp());
    t.set_scale(t1.get_scale());
    return t;
}

Temperature operator/(Temperature t1, Temperature t2)
{
    Temperature t;
    t.set_temp(t1.get_temp() / t2.get_temp());
    t.set_scale(t1.get_scale());
    return t;
}

bool operator==(Temperature t1, Temperature t2)
{
    return (t1.get_temp() == t2.get_temp());
}

bool operator!=(Temperature t1, Temperature t2)
{
    return (t1.get_temp() != t2.get_temp());
}

bool operator<(Temperature t1, Temperature t2)
{
    return (t1.get_temp() < t2.get_temp());
}

bool operator<=(Temperature t1, Temperature t2)
{
    return (t1.get_temp() <= t2.get_temp());
}

bool operator>(Temperature t1, Temperature t2)
{
    return (t1.get_temp() > t2.get_temp());
}

bool operator>=(Temperature t1, Temperature t2)
{
    return (t1.get_temp() >= t2.get_temp());
}

ostream& operator<<(ostream& out, Temperature t)
{
    out << t.get_temp() << " " << t.get_scale();
    return out;
}

istream& operator>>(istream& in, Temperature& t)
{
    double temp;
    char scale;
    in >> temp >> scale;
    t.set_temp(temp);
    t.set_scale(scale);
    return in;
}

void Temperature::set_temp(double temp)
{
    this->temp = temp;
}

void Temperature::set_scale(char scale)
{
    this->scale = scale;
}

double Temperature::get_temp()
{
    return temp;
}

char Temperature::get_scale()
{
    return scale;
}

int main(int argc, char **argv)
{
    Temperature t1(100, 'C');
    Temperature t2(212, 'F');
    Temperature t3(373.15, 'K');
    Temperature t4(100, 'C');
    vector<Temperature> temps;
    temps.push_back(t1);
    temps.push_back(t2);
    temps.push_back(t3);
    temps.push_back(t4);
    for (int i = 0; i < temps.size(); i++) {
        cout << temps[i] << endl;
    }
    /**
     * @brief test the other friend operators
     *
     */
    cout << "t1 + t2 = " << t1 + t2 << endl;
    cout << "t1 - t2 = " << t1 - t2 << endl;
    cout << "t1 * t2 = " << t1 * t2 << endl;
    cout << "t1 / t2 = " << t1 / t2 << endl;
    cout << "t1 == t2 = " << (t1 == t2) << endl;
    cout << "t1 != t2 = " << (t1 != t2) << endl;
    cout << "t1 < t2 = " << (t1 < t2) << endl;
    cout << "t1 <= t2 = " << (t1 <= t2) << endl;
    cout << "t1 > t2 = " << (t1 > t2) << endl;
    cout << "t1 >= t2 = " << (t1 >= t2) << endl;
    cout << "t1 == t4 = " << (t1 == t4) << endl;
    cout << "t1 != t4 = " << (t1 != t4) << endl;
    cout << "t1 < t4 = " << (t1 < t4) << endl;
    cout << "t1 <= t4 = " << (t1 <= t4) << endl;
    cout << "t1 > t4 = " << (t1 > t4) << endl;
    cout << "t1 >= t4 = " << (t1 >= t4) << endl;
    return 0;
}
