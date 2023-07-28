/**
 * Given an array of n elements, 
 * for each element perform either of the following operation exactly once:
 *  1. nums[i] = nums[i] + K
 *  2. nums[i] = nums[i] - K
 * 
 * Return the minimum possible value of max(nums) - min(nums) you can get at the 
 * end of n operations
*/

#include <vector>

int calculateMinimumDifference(vector<int>& heights, int K) {

    int length = heights.size();
    sort(heights.begin(), heights.end());
    int minimumDifference = heights;

    for(int i = 1; i<length; ++i) {
        int differenceAtPartitionI = max(heights[length-1]-K, heights[i-1]+K) - min(heights[0]+K, heights[i]-K);
        minimumDifference = min(minimumDifference, differenceAtPartitionI);
    }
    return minimumDifference;

}

