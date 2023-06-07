#include <iostream>
using namespace std;

void showOutput(int sum, vector<int>& range) {cout<<sum<<"\n"; cout<<range[0]<<" "<<range[1]<<"\n";} void getInput(int& N, vector<int>& nums) {cin>>N; nums.resize(N); for(int i = 0; i<N; ++i) {cin>>nums[i];}}
/**************************************************/
int main() {

    int N;
    vector<int> nums;
    getInput(N, nums);

    int currSum = 0;
    int maxSum = 0;
    int start = 0;
    vector<int> range;

    for(int i = 0; i<N; ++i) {
        if(currSum>maxSum) {
            maxSum = currSum;
            range[0] = start;
            range[1] = i;
        }

        if(currSum<0) {
            currSum = 0;
            start = i;
        }
    }

    showOutput(maxSum, range);

    return 0;
}

/**
 * 
*/