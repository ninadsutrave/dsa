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

LinkedListNode* reverse(LinkedListNode* head) {

    if(!head) return NULL;

    LinkedListNode* prev = NULL;
    LinkedListNode* current = head;
    LinkedListNode* next = current->next;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;

}

int main() {

    LinkedListNode* list = new LinkedListNode(3);
    list->next = new LinkedListNode(4);
    list->next->next = new LinkedListNode(12);
    list->next->next->next = new LinkedListNode(13);
    list->next->next->next->next = new LinkedListNode(16);

    LinkedListNode* head = reverse(list);
    while(list) {
        cout<<list->val<<" ";
        list = list->next;
    }

    return 0;
}

/**
 * 
 * 1. Move to every node
 * 2. Store its next node is a separate variable 
 * 3. Disconnect it from the next node
 * 4. Make the next value equal to previous node
 * 5. Now reset the problem, set previous equal to 
 *    current node, current equal to next node
 * 6. Iterate till current does not become null
 * 
 * 
 * https://gifyu.com/image/SQIdn
 * 
*/