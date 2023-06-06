#include <exception>
#include <iostream>
using namespace std;

double exp(double base, int power) {

    if(base == 0 && power == 0) {
        throw invalid_argument("Zero exponentiated by zero is indeterminate");
    }
    
    if(base == 0 || base == 1) return base;

    if(power == 0) return 1;

    if(power<0) {
        base = 1/base;
        power = -power;
    }

    double result = 1;
    while (power) {
        if (power&1) {
            result = result*base;
        }
        base = base*base;
        power = power>>1;
    }

    return result;

}   

int main() {

    cout<<exp(1,0)<<"\n";
    cout<<exp(8,-5)<<"\n";
    cout<<exp(0,0)<<"\n";

    return 0;

}

/**
 * Time Complexoty: O(logn)
 * If exponent -> even 
 * 
 * 
 * 
*/