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

LinkedListNode* findMiddle(LinkedListNode* head) {

    LinkedListNode* slow = head;
    LinkedListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; 

}

LinkedListNode* merge(LinkedListNode* left, LinkedListNode* right) {

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

LinkedListNode* mergeSort(LinkedListNode* head) {

    if(head == NULL || head->next == NULL) return head;

    LinkedListNode* mid = findMiddle(head);

    LinkedListNode* right = mid->next;
    LinkedListNode* left = head;
    mid->next = NULL;        // left segment is only upto the mid thus ending with null

    left = mergeSort(left);
    right = mergeSort(right);

    LinkedListNode* result = merge(left, right);
    return result;

}

int main() {
    LinkedListNode* head = new LinkedListNode(5);
    head->next = new LinkedListNode(10);
    head->next->next = new LinkedListNode(2);
    head->next->next->next = new LinkedListNode(7);
    head->next->next->next->next = new LinkedListNode(9);
    head->next->next->next->next->next = new LinkedListNode(3);

    LinkedListNode* result = mergeSort(head);

    while(result) {
        cout<<result->val<<" ";
        result = result->next;
    }

    return 0;
}

/**
 * Prereqs: 
 *  a. Find middle of linked list
 *  b. Merging two sorted lists
 * 
 * Unlike other sorting algorithms like Quick Sort or Heap Sort, Merge Sort's performance
 * is not significantly affected by the lack of random access in linked lists
 * 
 * Also, in linked lists, we can insert items in the middle in O(1) space
 * and O(1) time if we have the reference to the previous node. The merge 
 * step of the algorithm thus can now be performed without extra space
 * 
 * Quick Sort requires a lot of random accessing of the elements. In linked list to access i’th index, 
 * we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. 
 * Therefore, the overhead increases for quick sort and makes it inefficient
 * 
*/