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

LinkedListNode* mergeTwoSortedLists(LinkedListNode* left, LinkedListNode* right) {

    if(left == NULL) return right;
    if(right == NULL) return left;

    LinkedListNode* result = new LinkedListNode();
    LinkedListNode* temp = result;

    while(left != NULL && right != NULL) {

        if(left->val < right->val) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }

        temp = temp->next;
    }

    if(left != NULL) temp->next = left;
    if(right != NULL) temp->next = right;

    return result->next;

}

int main () {
    LinkedListNode* list1 = new LinkedListNode(5);
    list1->next = new LinkedListNode(10);
    list1->next->next = new LinkedListNode(15);
    list1->next->next->next = new LinkedListNode(17);

    LinkedListNode* list2 = new LinkedListNode(3);
    list2->next = new LinkedListNode(4);
    list2->next->next = new LinkedListNode(12);
    list2->next->next->next = new LinkedListNode(13);
    list2->next->next->next->next = new LinkedListNode(16);

    LinkedListNode* merged = mergeTwoSortedLists(list1, list2);

    while(merged) {
        cout<<merged->val<<" ";
        merged = merged->next;
    }

    return 0;
}
