#include <iostream>
#include <cstdarg>
using namespace std;

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int result = 0;

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        result = result + num;
    }

    va_end(args);
    return result;
}

void customPrintf(char* format, ...) {
    va_list args;
    va_start(args, format);
    
    while (*format != '\0') {

        if (*format == '%') {
            ++format;
            
            switch (*format) {
                case 'd': {
                    int num = va_arg(args, int);
                    cout<<num;
                    break;
                }
                case 'f': {
                    double num = va_arg(args, double);
                    cout<<num;
                    break;
                }
                case 's': {
                    const char* str = va_arg(args, const char*);
                    cout<<str;
                    break;
                }
                default:
                    cout<<*format;
            }
        }
        else {
            cout<<*format;
        }
        
        ++format;
    }
    
    va_end(args);
}

int main() {

    customPrintf("%s %d %f", "Yo", 42, 3.14159);
    cout<<"\n";

    cout<<sum(3, 10, 20, 30)<<"\n";
    
    return 0;
}

/**
 * 
 * Variadic functions are functions that can take in variable arguments
 * Any mumber of arguments and any type of arguments
 * 
 * va_list is a type defined in <cstdarg> that is used to hold the 
 * information about the variable arguments in a variadic function
 * 
 * va_start and va_end are macros defined in <cstdarg>
 * 
 * va_start - It initializes the va_list object with the variable arguments 
 * passed to the variadic function
 * 
 * va_end  - It cleans up the va_list object after all the variable arguments 
 * have been processed in the variadic function
 * 
 * The most common usage of variadic functions are printf() and scanf() 
 * Here I have implemented a printf function which demonstrates how the 
 * printf function actually formats the text given as the first argument
 * 
 * There also exist variadic templates, which are used for implementations
 * such as the tuple class 
 * (which takes in multiple elments of varied types)
 *
 * template<typename... Args>
 *
 * (Check tuple.cpp in implementations)
 * 
*/