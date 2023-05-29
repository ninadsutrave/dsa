#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high]; 
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (nums[j] <= pivot) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1; 
}

void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(nums, low, high);
        quickSort(nums, low, partitionIndex - 1);
        quickSort(nums, partitionIndex + 1, high);
    }
}

int main() {
    vector<int> nums = {9, 5, 7, 1, 3, 10, 4, 2, 6, 8};
    int n = nums.size();

    quickSort(nums, 0, n - 1);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}


/**
 * 
 * Quick sort works on the concept that, 
 * if for an element in the numsay, all elements before it are smaller,
 * and all elements after it are larger, then it is at its sorted position.
 * 
 * Best case time complexity: O(nlogn)
 * (achieved when pivot chosen is always the median)
 * 
 * Worst case time complexity: O(n^2)
 * (numsay is already sorted then pivot chosen is always at the beginning or end)
 * (results in very uneven partitions like of length n-1 and 1)
 * 
 * Average case time compleity: O(nlogn)
 * (choosing random pivot has expected complexity of nlogn)
 * 
 * Space complexity: O(n) call stack size
 * 
 **/