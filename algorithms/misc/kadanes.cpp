#include <iostream>
using namespace std;

pair<int,int> kadanes(vector<int>& nums) {

    pair<int,int> range;
    int length = nums.size();
    int currSum = 0;
    int maxSum = 0;
    int start = 0;

    for(int i = 0; i<length; ++i) {
        if(currSum>maxSum) {
            maxSum = currSum;
            range.first = start;
            range.second = i;
        }

        if(currSum<0) {
            currSum = 0;
            range.first = i;
        }
    }

    return range;

}

int main() {

    vector<int> nums {9,-2,5,6,0,1,2,-1,9,0,4,14};

    pair<int,int> range = kadanes(nums);
    long long sum = 0;

    for(int i = range.first; i<=range.second; ++i) {
        sum = sum + nums[i];
    }

    cout<<sum<<"\n";

    return 0;
}

/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
*/