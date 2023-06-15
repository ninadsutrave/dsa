#include <iostream>
using namespace std;

template<typename... Ts>
class Tuple {
    public:
        Tuple(const Ts&... values) : elements(values...) {}

        template<size_t Index>
        auto get() const {
            return get<Index>(elements);
        }

    private:
        tuple<Ts...> elements;
};

int main() {

    Tuple<int, double, string> tuple(42, 3.14, "Hello");

    cout<<tuple.get<0>()<<"\n";  
    cout<<tuple.get<1>()<<"\n"; 
    cout<<tuple.get<2>()<<"\n"; 

    return 0;
}

/**
 * Variadic functions:
 * void printValues(const char* format, ...);
 * 
 * Variadic templates:
 * template<typename... Args>
 * void printValues(Args... args);
 * 
 * It is used when there could be a variable number of 
 * arguments in the function/template
*/