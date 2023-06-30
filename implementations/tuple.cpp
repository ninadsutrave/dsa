#include <iostream>
using namespace std;

template<typename... Types>
class Tuple {
    public:
        Tuple(const Types&... values) : elements(values...) {}

        template<size_t Index>
        auto get() const {
            return get<Index>(elements);
        }

    private:
        tuple<Types...> elements;

        template<size_t Index, typename Tuple>
        auto get(const Tuple& t) const {
            if constexpr (Index >= tuple_size_v<Tuple>) {
                throw out_of_range("Index out of range");
            } else {
                return get<Index>(t);
            }
        }
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