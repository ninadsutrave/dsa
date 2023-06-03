#include <iostream>
using namespace std;

struct LinkedListNode {
    int val;
    LinkedListNode* next;
    LinkedListNode() {
        val = 0;
        next = nullptr;
    }
    LinkedListNode(int data) {
        val = data;
        next = nullptr;
    }
};

bool isCyclic(LinkedListNode* head) {

    LinkedListNode* slow = head;
    LinkedListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
}

int main() {
    LinkedListNode* head = new LinkedListNode(5);
    head->next = new LinkedListNode(10);
    head->next->next = new LinkedListNode(2);
    head->next->next->next = new LinkedListNode(7);
    head->next->next->next->next = head->next;

    cout << isCyclic(head);
}