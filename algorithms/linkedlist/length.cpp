#include <iostream>
using namespace std;

struct LinkedListNode {
    int val;
    LinkedListNode* next;
    LinkedListNode() {
        val = 0;
        next = NULL;
    }
    LinkedListNode(int data) {
        val = data;
        next = NULL;
    }
};

int calcLength(LinkedListNode* head) {
    
    int length;
    for(length = 0; head; head = head->next)
        ++length;

    return length;

}

int getLength(LinkedListNode* head) {
    if(!head) return 0;
    return getLength(head->next) + 1;
}

int main() {

    LinkedListNode* head = new LinkedListNode(5);
    head->next = new LinkedListNode(10);
    head->next->next = new LinkedListNode(2);
    head->next->next->next = new LinkedListNode(7);
    head->next->next->next->next = new LinkedListNode(14);

    cout << getLength(head);

    return 0;
}