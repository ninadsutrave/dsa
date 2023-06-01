#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> elementsOccuringGreaterThanNByKTimes(vector<int>& nums, int k) {

    if(k == 1) {
        return {};
    }

    vector<int> count(k-1,  0);
    vector<int> currMajor(k-1);

    for(int num: nums) {

        // update frequency
        int i;
        for (i = 0; i<k-1; ++i) {
            if (currMajor[i] == num) {
                ++count[i];
                break;
            }
        }

        // if num is not present as any currMajor
        if(i == k-1) {

            // assign currMajor to elements whose count is 0
            int j;
            for(j = 0; j<k-1; ++j) {
                if(count[j] == 0) {
                    currMajor[j] = num;
                    ++count[j];
                    break;
                }
            }

            // if all currMajor are already assigned decrement all counters by 1
            if(j == k-1) {
                for(j = 0; j<k-1; ++j) {
                    --count[j];
                }
            }
        }
    }

    int criteria = nums.size()/k;
    set<int> all;

    for(int curr: currMajor) {
        int freq = 0;
        for(int num: nums) {
            if(num == curr) {
                ++freq;
            }
        }
        if(freq>criteria) {
            all.insert(curr);
        }
    }

    vector<int> result(all.begin(), all.end());
    return result;

}

int elementOccuringMoreThanNBy2Times(vector<int>& nums) {

    //  Cancel occurrence of current element with the count of current major element
    //  Repeat this process and update current major element when count becomes 0
    //  The final major element would be our answer
    
    int count = 0;
    int currMajor;

    for (int num : nums) {
        if (count == 0) {
            currMajor = num;
        }
        if(currMajor == num) {
            ++count;
        } else {
            --count;
        }
    }
    return currMajor;
        
}

int main() {

    vector<int> nums {2, 5, 6, 2, 2, 6, 4, 7, 5, 2, 2, 5, 2, 7, 5};

    //  Boyer-Moore Voting Algorithm
    //  Cancel occurrence of current element with the current major element
    //  Repeat this process, and the remaining element would be our answer 
    vector<int> result = elementsOccuringGreaterThanNByKTimes(nums, 3);
    for(int num: result) {
        cout << num << " ";
    }

    return 0;

}