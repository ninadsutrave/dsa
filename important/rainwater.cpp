/* https://leetcode.com/problems/trapping-rain-water/ */
#include <vector>
#include <iostream>
using namespace std;

int calculateRainWater(vector<int>& height) {

    int length = height.size();
    int ans = 0; 

    int left, right;
    int leftMax, rightMax;

    leftMax = rightMax = 0;
    left = 0;
    right = length-1;

    while(left<right) {

        if(height[left]<height[right]) {

            if(leftMax<height[left]) {
                leftMax = height[left]; // in this case water isn't trapped on top 
            } else {
                ans = ans + (leftMax-height[left]); // water is trapped and is equal to difference in heights
            }  

            ++left;

        } else {
            
            if(rightMax<height[right]) {
                rightMax = height[right]; // in this case water isn't trapped on top 
            } else {
                ans = ans + (rightMax-height[right]); // water is trapped and is equal to difference in heights
            }

            --right;

        }
    }
    
    return ans;

}

int main() {

    vector<int> heights {0,1,0,2,1,0,1,3,2,1,2,1,4,2,0,3,2,5};

    cout<<calculateRainWater(heights)<<"\n";

    return 0;
}

/**
 * This problem is all about visualisation
 * 
 * Realise that:
 *  1. The level of water accumulated between two buildings
 *      = the minimum of height of both the buldings
 * 
 *  2. There will be accumulated above a building, only if it has a building 
 *     on the left and on the right with greater height
 * 
 *  3. So it is a good idea to use a two pointer approach, so that we can track the
 *     largest building on the left and the right
 * 
 *  4. After moving a pointer, water will only be counted if the new building 
 *     size is lesser (as concluded from point 3)
 * 
 *  5. And since water level is dependent on the minimum of left and right
 *     we must move the pointer which has lesser height
 * 
 *  Check example of [4,2,3]
 *  We must move pointer at 3, moving ponter at 4 will give wrong result
*/
