/* https://www.geeksforgeeks.org/count-number-subarrays-given-xor/ */
/* https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/ */

// Count number of subarrays with XOR value equal to K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long findSubarrays(vector<int>& nums, int K) {

    int length = nums.size();
    unordered_map<int, int> prefixCount;
 
    vector<int> prefix(length);
    prefix[0] = nums[0];
    for(int i = 1; i<length; ++i) {
        prefix[i] = nums[i]^prefix[i-1];
    }

    long long ans = 0;
 
    for (int i = 0; i<length; ++i) {
       
        int xorValue = K ^ prefix[i];
        ans = ans + prefixCount[xorValue];

        if (prefix[i] == K)
            ++ans;
 
        ++prefixCount[prefix[i]];
    }

    return ans;

}

int main() {

    vector<int> arr{6, 5, 2, 7, 8, 14, 6, 2};
    int K = 4;

    cout<< findSubarrays(arr, K) << "\n";

    return 0;
}