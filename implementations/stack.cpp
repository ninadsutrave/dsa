#include <exception>
#include <iostream>
using namespace std;

template <typename T>
class Stack {

    private:
    struct LinkedListNode {
        T val;
        LinkedListNode* next;
        LinkedListNode(const T& data) {
            val = data;
            next = nullptr;
        }
    };
    LinkedListNode* topPtr;
    size_t currentSize;

    public:
    Stack() {
        currentSize = 0;
        topPtr = nullptr;
    }

    ~Stack() {
        while (currentSize) {
            pop();
        }
    }

    void push(const T& value) {

        LinkedListNode* newNode = new LinkedListNode(value);
        newNode->next = topPtr;
        topPtr = newNode;

        ++currentSize;

    }

    void pop() {

        if(currentSize == 0) {
            throw out_of_range("Stack is empty");
        } 

        LinkedListNode* oldNode = topPtr;
        topPtr = topPtr->next;
        delete oldNode;

        --currentSize;

    }

    const T& top() {
        if(topPtr) {
            return topPtr->val;
        } else {
            throw out_of_range("Stack is empty");
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

    Stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(6);
    s.push(1);
    s.push(9);
    s.push(-4);

    cout<<s.size()<<"\n";
    cout<<s.top()<<"\n";

    s.pop();
    s.pop();

    cout<<s.size()<<"\n";
    cout<<s.top()<<"\n";

    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<s.empty()<<"\n";


    return 0;
}

/**
 * All operations are O(1) time 
 * 
 * topPtr is always pointing to the last added node
 * thus for pop operations just push topPtr to next pointer
 * 
 * for push operations create a new node poining to topPtr 
 * and then update topPtr to the new node
*/