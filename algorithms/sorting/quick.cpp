#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandomPivot(int low, int high) {
    srand(time(NULL));
    return low + rand() % (high - low + 1);
}

int partition(vector<int>& nums, int low, int high) {

    /**
     * 1. Find a random pivot
     * 2. Move it to the end of the array
     * 3. Partition the remaining elements
     * 4. Insert pivot at designated position
    */

    int pivotIndex = getRandomPivot(low, high);
    int pivot = nums[pivotIndex]; 
    int i = low - 1;

    /**
     * Dry run on paper to fully understand!
     * 
     * initially i is before the starting element
     * as the iterator proceeds, it places smaller 
     * elements at the beginning and i is incremented
    */

    swap(nums[pivotIndex], nums[high]);
    for (int j = low; j<high; ++j) {
        if (nums[j] <= pivot) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[pivotIndex]);

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
    vector<int> nums {9, 5, 7, 1, 3, 10, 4, 2, 6, 8};
    int n = nums.size();

    quickSort(nums, 0, n - 1);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}


/**
 * 
 * Recurrence: T(n) = T(k) + T(n-k-1) + O(n)
 * O(n) -> time reqd for partitioning
 * k and n-k+1 are sizes of the partitions
 * 
 * Quick sort works on the concept that, 
 * if for an element in the array, all elements before it are smaller,
 * and all elements after it are larger, then it is at its sorted position.
 * 
 * Quick sort is NOT a stable sorting algorithm.
 * 
 * Best case time complexity: O(nlogn)
 * (achieved when pivot chosen is always the median, thus equal partitions are formed)
 * 
 * Worst case time complexity: O(n^2)
 * (pivot chosen is always at the beginning or end - for eg if array is sorted and we are choosing pivot arr[0] or arr[n-1])
 * (results in very uneven partitions like of length n-1 and 1)
 * 
 * Average case time compleity: O(nlogn)
 * (choosing random pivot has expected complexity of nlogn)
 * 
 * 
 * Best pivoting techniques:
 * (in practice quick sort is faster than merge sort, so this is very crucial)
 *  1. Random pivoting
 *  2. Median of first, last and middle element
 *  3. Randomly select three array elements and take their median
 * 
 * 
 * The call stack size contributes to the space complexity
 * Best Case Space Complexity: O(logn) when arrays partition equally always 
 * Worst Case Space complexity: O(n) when arrays partition very unevenly
 * 
 * C++ sorting functions:
 *  1. sort():   
 *     Algorithm - Introsort (Hybrid of Quicksort, Heap Sort and Insertion Sort) 
 *     Best/Average/Worst - O(NlogN)
 *     Auxiliary Space- O(logN)
 *     Stable - No
 * 
 *  2. stable_sort():   
 *     Algorithm - Merge Sort
 *     Best/Average/Worst - O(NlogN)
 *     Auxiliary Space- O(N)
 *     Stable - Yes
 * 
 *  3. qsort():   
 *     Algorithm - Quick Sort
 *     Best/Average - O(NlogN), Worst - O(N^2)
 *     Auxiliary Space- O(logN)
 *     Stable - Depends on comparator function
 * 
 **/