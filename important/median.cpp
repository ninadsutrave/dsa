/* https://leetcode.com/problems/median-of-two-sorted-arrays/ */

#include <iostream>
#include <vector>
using namespace std;

double getMedian(vector<int>& arr1, vector<int>& arr2) {

    

}

int main() {

    //  1   2   3
    //  2

    vector<int> arr1 {1, 2, 2, 4, 5, 6, 11, 11, 12, 14, 15};
    vector<int> arr2 {2, 5, 5, 7, 9, 10, 11, 11, 12};

    cout<<getMedian(arr1, arr2)<<"\n";

    return 0;
}