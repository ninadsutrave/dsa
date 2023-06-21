/* https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article */
/* first thoroughly understand inversions1 
 * given an array, find number of pairs of elements
 * such that A[i] > A[j] where i<j
*/

#include <iostream>
#include <vector>
using namespace std;

void countAndMerge(vector<int>& arr, int start, int mid, int end, int& count) {

    vector<int> merged(end-start+1);

    int left = start;
    int right = mid+1;
    int index = 0;

    while(left<=mid && right<=end) {
        if(arr[left]<arr[right]) {
            merged[index] = arr[left];
            ++left;
        } else {
            count = count + (mid - left + 1);    // add inversion count when arr[left] > arr[right]
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

void divide(vector<int>& nums, int start, int end, int& count) {

    if(start>=end) {
        return;
    }

    int mid = start + (end-start)/2;
    divide(nums, start, mid, count);
    divide(nums, mid+1, end, count);
    countAndMerge(nums, start, mid, end, count);

}

int main() {
    vector<int> nums {5, 3, 2, 4, 1};
    int n = nums.size();

    int count = 0;
    divide(nums, 0, n - 1, count);

    cout<<count<<"\n";

    return 0;

}

/**
 * 
 * Since we know how to count inversion from two sorted arrays,
 * we use merge sort, which uses a divide and merge algorithm,
 * to count inversions at every division in O(n) time
 * 
 * Thus resultant worst time complexity stays O(nlogn)
 * 
*/