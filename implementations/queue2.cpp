// implement a queue using 2 stacks

#include <exception>
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class Queue {

    private: 
    stack<T> data;
    stack<T> helper;
    size_t currentSize;
    T frontValue;

    public:
    Queue() {
        currentSize = 0;
    }

    ~Queue() {
        while(currentSize) {
            dequeue();
        }
    }

    void enqueue(const T& value) {

        if(currentSize == 0) frontValue = value;

        data.push(value);
        ++currentSize;
    }

    void dequeue() {

        if(empty()) {
            throw out_of_range("Queue is empty");
        }

        while(data.size()) {
            helper.push(data.top());
            data.pop();
        }

        helper.pop();
        frontValue = helper.top();

        while(helper.size()) {
            data.push(helper.top());
            helper.pop();
        }

        --currentSize;

    }

    const T& front() {

        if(empty()) {
            throw out_of_range("Queue is empty");
        }

        return frontValue;
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

    cout<<q.empty()<<"\n";

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(1);
    q.enqueue(8);
    q.dequeue();
    q.enqueue(3);
    q.enqueue(12);

    cout<<q.size()<<"\n";
    cout<<q.front()<<"\n";

    return 0;
}