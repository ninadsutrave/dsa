#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class Vector {

    private:
    T* data;
    size_t currentSize;

    public:
    Vector() {
        currentSize = 0;
    }

    Vector(size_t size) {
        currentSize = size;
        data = new T[size];

        for (long long i = 0; i<size; ++i) {
            data[i] = 0;
        }
    }

    Vector(size_t size, const T& value) {
        currentSize = size;
        data = new T[size];

        for (long long i = 0; i<size; ++i) {
            data[i] = value;
        }
    }

    ~Vector() {
        delete[] data;
    }

    // return value is a reference, to allow assingment operation like arr[5] = 10
    T& operator[](size_t index) {
        return data[index];
    }

    void push_back(const T& value) {

        T* resizedArray = new T[currentSize+1];
        for(int i = 0; i<currentSize; ++i) {
            resizedArray[i] = data[i];
        }
        resizedArray[currentSize] = value;

        delete[] data;

        data = resizedArray;
        ++currentSize;
    }

    void pop_back() {

        if(currentSize == 0) {
            throw out_of_range("Vector is empty");
        }
        --currentSize;
    }

    size_t size() {
        return currentSize;
    }

};

int main() {

    Vector<int> myvector(5);

    for(int i = 0; i<5; ++i) {
        myvector[i] = i;
    }

    myvector.push_back(2);
    myvector.push_back(8);
    myvector.pop_back();

    for(int i = 0; i<myvector.size(); ++i) {
        cout<<myvector[i]<<" ";
    }

    cout<<myvector.size()<<" ";

    return 0;
}

/**
 * push_back(val): O(n)
 * Because length is increase by 1 and new space 
 * of size n+1 is dynamically allocated
 * 
 * pop_back():     O(1)
 * Because only length is decremented by 1
 * 
 * size():         O(1)
 * Value of member variable is returned
*/