// implement a queue using stacks

#include <exception>
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class Queue {

    private: 
    stack<T> data;
    stack<T> helper;
    size_t currSize;
    T frontValue;

    public:
    Queue() {
        currSize = 0;
    }

    ~Queue() {
        currSize = 0;
        while(data.size()) {
            data.pop();
        }
    }

    void enqueue(const T& value) {

        if(currSize == 0) frontValue = value;

        data.push(value);
        ++currSize;
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

        --currSize;

    }

    const T& front() {

        if(empty()) {
            throw out_of_range("Queue is empty");
        }

        return frontValue;
    }

    const T& back() {

        if(empty()) {
            throw out_of_range("Queue is empty");
        }

        return data.top();
    }

    bool empty() {
        return (currSize == 0);
    }

    size_t size() {
        return currSize;
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
    cout<<q.back()<<"\n";

    return 0;
}