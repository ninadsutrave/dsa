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

    double result = exp(base, power/2);

    if(power&1) {
        result = result*result*base;
    } else {
        result = result*result;
    }

    return result;

}   

int main() {

    cout<<exp(1,0)<<"\n";
    cout<<exp(8,-5)<<"\n";
    cout<<exp(0,50)<<"\n";

}