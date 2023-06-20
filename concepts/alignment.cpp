#include <iostream>
using namespace std;

class Random {
    public:
    int value;
    bool check;
    void count() {}
};

struct collection {
    char character;      // 1 byte
    int integer;        // 4 byte
    int integer2;       // 4 byte
};

int main () {

    collection a;
    cout<<sizeof(a)<<"\n";  // output: 12 byte
    // assigns character a padding of 3 byte for easy retrieval and minimal overhead

    Random r;
    cout<<sizeof(r)<<"\n"; // output: 8 byte

    return 0;

}

/**
 *
 * When a structure or class is defined, the compiler automatically determines the alignment 
 * requirements for its members. It ensures that each member is positioned at an appropriate 
 * memory offset, respecting the alignment rules of the data types involved.
 * The alignment of members can affect the overall size of the structure or class. 
 * 
 * For example, 
 * if a member has a larger alignment requirement, it may introduce padding between members to 
 * maintain proper alignment. This padding ensures that subsequent members are properly aligned 
 * according to their requirements.
 * 
 * By aligning the members, the compiler ensures that accessing the members of a structure or 
 * class is efficient, as the members are correctly aligned in memory and can be accessed with 
 * minimal overhead.
 * 
 * bool         1 byte
 * char         1 byte        0 to 256
 * short        2 bytes       -2^15 to 2^15 - 1 
 * long         4 bytes       -2^31 to 2^31 - 1
 * long long    8 bytes       -2^64 to 2^64 - 1
 * 
 * float        4 bytes
 * double       8 bytes
 * 
 * Although conceptually a boolean value could be represented using just 1 bit, 
 * using 1-bit memory cells in typical computer architectures is not efficient. 
 * The smallest addressable unit of memory in most systems is a byte (8 bits). 
 * Accessing individual bits within a byte requires additional instructions and 
 * operations, making it less efficient.
 * 
*/