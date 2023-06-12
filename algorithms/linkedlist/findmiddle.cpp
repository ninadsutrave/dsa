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

LinkedListNode* findMiddleElement(LinkedListNode* head) {

    if(head == NULL) return head;
    
    LinkedListNode* slow = head;
    LinkedListNode* fast = head->next;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main () {
    LinkedListNode* head = new LinkedListNode(5);
    head->next = new LinkedListNode(10);
    head->next->next = new LinkedListNode(2);
    head->next->next->next = new LinkedListNode(7);

    cout << findMiddleElement(head)->val <<"\n";

    return 0;
}

/**
 * Time Complexity: O(n) 
 * Space Complexity: O(1)
*/