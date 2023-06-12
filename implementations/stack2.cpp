// implement a stack using two queues

#include <queue>
#include <iostream>
#include <exception>
using namespace std;

template <typename T> 
class Stack {

    private:
    queue<T> data;
    queue<T> helper;
    size_t currentSize;
    T topValue;

    public:
    Stack() {
        currentSize = 0;
    }

    ~Stack() {
        while(currentSize) {
            pop();
        }
    }

    void push(const T& value) {

        topValue = value;
        data.push(value);
        ++currentSize;

    }

    const T& pop() {

        if(data.size() == 0) {
            throw out_of_range("Stack is empty");
        }

        while(data.size()>1) {
            helper.push(data.front());
            data.pop();
        }

        T temp = data.front();
        data.pop();
        --currentSize;

        if(helper.size() == 0) return temp;

        while(helper.size()) {
            topValue = helper.front();
            data.push(topValue);
            helper.pop();
        }

        return temp;

    }

    const T& top() {
        return topValue;
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