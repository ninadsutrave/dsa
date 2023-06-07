#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& nums) {

    int n = nums.size();

    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

}

int main() {
    vector<int> nums {9, 5, 7, 1, 3, 10, 4, 2, 6, 8};

    bubbleSort(nums);

    for(int num: nums) {
        cout<<num<<" ";
    }

    return 0;
}

/**
 * Honestly, not worth studying lol
 * Anyway it compares all adjacent elements and shifts
 * larger elements towards the end. Thus the array is sorted
 * in atmost n iterations.
 * 
 * Worst Time Complexity: O(n^2)
 * (when array is reverse sorted)
 * It performs n*(n-1)/2 comparisons and swaps
 * 
 * Best Time Complexity: O(n) 
 * (when array is already sorted)
 * 
 * Space Complexity: O(1)
 * 
*/