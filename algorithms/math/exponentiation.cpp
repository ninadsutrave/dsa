#include <exception>
#include <iostream>
using namespace std;

double exp(double base, int power) {

    if(base == 0 && power <= 0) {
        throw invalid_argument("Result is not defined");
    }
    
    if(base == 0 || base == 1) return base;

    if(power == 0) return 1;

    if(power<0) {
        base = 1/base;
        power = -power;
    }

    double result = 1;
    while (power) {
        if (power&1) result = result*base;
        base = base*base;
        power = power>>1;
    }

    /**
     * Dry Run for 3^11: 
     *              result =   1, base =   3, power = 11
     * Iteration 1: result =   3, base = 3^2, power = 5
     * Iteration 2: result = 3^3, base = 3^4, power = 2
     * Iteration 3: result = 3^3, base = 3^8, power = 1
     * Iteration 4: result = 3^11, base = 3^16, power = 0 
    */

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
 * 
 * Recursive nature
 * f(a, b) =    f(a, b/2).f(a, b/2)   n: even
 *         = a. f(a, b/2).f(a, b/2)   n: odd
 * 
 * a^b = a^(b/2). a^(b/2)
*/