
// C++ program for Babylonian
// method for square root
#include <iostream>
using namespace std;
 
class gfg {
 
    /* Returns the square root of
   n. Note that the function
   will not work for numbers
   which are not perfect
   squares*/
public:
    float squareRoot(float n)
    {
        /* We are using n itself as an initial
          approximation.  This can definitely be
          improved */
        float x = n;
        float y = 1;
 
        while (x > y) {
            x = (x + y) / 2;
            y = n / x;
        }
        return x;
    }
};

float squareRoot (float n) {
    float x = n;
    float y = 1; 
    while (x > y) {
        x = (x+y)/2; 
        y = n/x; 
    }
    return x;
}
 
/* Driver code*/
int main(int argc, char ** argv)
{
    gfg g;
    float n = 0; 
    float squareRootValue = 0; 
    cout << "Enter the value of n: "; 
    cin >> n; 
    squareRootValue = squareRoot(n); 
    cout << "Square root of " << n << " is "  << squareRootValue << endl;
    return 0;
}