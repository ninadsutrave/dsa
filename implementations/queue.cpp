#include <exception>
#include <stddef.h>
#include <iostream>
using namespace std;

template <typename T>
class Queue {

    private:
    struct LinkedListNode {
        T val;
        LinkedListNode* next;
        LinkedListNode (const T& data) {
            val = data;
            next = nullptr;
        }
    };

    LinkedListNode* frontPtr;
    LinkedListNode* backPtr;
    size_t currentSize;

    public:
    Queue() {
        frontPtr = nullptr;
        backPtr = nullptr;
        currentSize = 0;
    }

    ~Queue() {
        while (currentSize) {
            dequeue();
        }
    }

    void enqueue(const T& value) {

        LinkedListNode* newNode = new LinkedListNode(value);
        if(currentSize == 0) {
            frontPtr = backPtr = newNode;
        } else {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        ++currentSize;

    }

    void dequeue() {

        if(currentSize == 0) {
            throw out_of_range("Queue is empty");
        } 

        LinkedListNode* oldNode = frontPtr;
        frontPtr = frontPtr->next;
        delete oldNode;

        if(frontPtr == nullptr) {
            backPtr = nullptr;
        }
        --currentSize;

    }

    const T& front() {

        if(frontPtr) {
            return frontPtr->val;
        } else {
            throw out_of_range("Queue is empty");
        }

    }

    const T& back() {

        if(backPtr) {
            return backPtr->val;
        } else {
            throw out_of_range("Queue is empty");
        }

    }
    
    bool empty() {
        return (currentSize == 0);
    }

    size_t size() {
        return currentSize;
    }

};


int main() {

    Queue<int> q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.dequeue();
    cout<<q.size()<<"\n";
    cout<<q.empty()<<"\n";
    cout<<q.front()<<"\n";
    cout<<q.back()<<"\n";

}

/**
 * size_t is a data type used to describe sizes of data structures and
 * is capable of representing the size of the largest possible object
 * if we used int we would have to handle cases of overflow
 * 
 * const keyword is explcitly used for parameters to ensure that the 
 * class methods cannot modify the value of the data
 * 
 * 
 * enqueue()   --> O(1) 
 * dequeue()   --> O(1)
 * front()     --> O(1)
 * back()      --> O(1)
 * size()      --> O(1)
 * empty()     --> O(1)
 * 
 * LinkedList is preferred over array because:
 *  -> Arrays may need frequent resizing which is costly
 * 
 * But if maximum size is known before hand, 
 * array will be preferred because there won't be extra
*/