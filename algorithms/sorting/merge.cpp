#include <iostream>
#include <vector>
using namespace std;

void mergeTwoSortedSegments(vector<int>& arr, int start, int mid, int end) {

    vector<int> merged(end-start+1);

    int left = start;
    int right = mid+1;
    int index = 0;

    while(left<=mid && right<=end) {
        if(arr[left]<arr[right]) {
            merged[index] = arr[left];
            ++left;
        } else {
            merged[index] = arr[right];
            ++right;
        }
        ++index;
    }

    while(left<=mid) {
        merged[index] = arr[left];
        ++index;
        ++left;
    }

    while(right<=end) {
        merged[index] = arr[right];
        ++index;
        ++right;
    }

    for(int num: merged) {
        arr[start] = num;
        ++start;
    }

}

void mergeSort(vector<int>& nums, int start, int end) {

    if(start>=end) {
        return;
    }

    int mid = start + (end-start)/2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid+1, end);
    mergeTwoSortedSegments(nums, start, mid, end);

}

int main() {
    vector<int> nums {9, 5, 7, 1, 3, 10, 4, 2, 6, 8};
    int n = nums.size();

    mergeSort(nums, 0, n - 1);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;

}

/**
 * 
 * Recurrence relation: T(n) = 2 * T(n/2) + O(n)
 * O(n) -> time taken for merging
 * 
 * Merge sort follows the divide-and-conquer paradigm. It efficiently sorts an array 
 * by recursively dividing it into smaller subarrays, sorting them independently, and then merging them.
 * It explots the facts that: 
 *   a) an array with a single element is a sorted array (base case)
 *   b) two sorted arrays can be merged in linear time
 * 
 * Key points:
 *  1. It is a stable sorting algorithm
 *  2. It is used for external sorting (sorting large datasets that do not fit entirely in memory
 *     where data needs to be sorted from disk to memory and vice versa)
 *  3. It is used to count inversions in an array
 *  4. It is the best algorithm to sort linked lists
 * 
 * Time Complexity: O(nlogn) in all cases
 * 
 * Worst Case: when input array is reverse sorted (or has many inversions)
 * ~n^2 comparisons in the merging step
 * 
 * Best Case: when input array is already sorted (or has low inversions)
 * very less number of comparisons needed
 * 
 * Space Complexity: O(n + logn) 
 * (space of extra merged array used for sorting array segments, and recursion stack)
 * 
*/