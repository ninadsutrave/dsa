/*INCOMPLETE*/
#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class List {

    private: 
    struct DoublyLinkedListNode {
        T val;
        DoublyLinkedListNode* next;
        DoublyLinkedListNode* prev;        

        DoublyLinkedListNode (const T& data) {
            val = data;
            next = nullptr;
            prev = nullptr;
        }
    };

    DoublyLinkedListNode* headNode;
    DoublyLinkedListNode* tailNode;
    size_t currentSize;

    public:
    List() {
        headNode = tailNode = nullptr;
    }

    ~List() {
        while(currentSize()) {
            pop_back();
        }
    }

    void push_back(const T& val) {

        DoublyLinkedListNode* node = new DoublyLinkedListNode(val);

        if(headNode == nullptr) {
            headNode = tailNode = node;
        } else {
            
        }
    }

};