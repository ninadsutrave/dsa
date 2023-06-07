/* https://www.youtube.com/watch?v=AseUmwVNaoY
   pre requisite to understanding inversions2.cpp */

/**
 * Given two sorted arrays A and B, find number of pairs 
 * A[i], B[j], such that A[i] < B[j]
 * 
 * i = 0             j = 0
 * A = [2,3,5,6]     B = [2,2,4,4,8]
 * A[0] = 2          B[0] = 2
 * 
 * (2,2) cannot form an inversion so i = i+1
 * 
 * A[1] = 3         B[0] = 2
 * 
 * since A[1] > B[0]
 * it is guaranteed that A[2], A[3], A[4] > B[0]
 * so we add all of these to our result
 * count = count + (length-i)  =  3
 * increment j
 * 
 * A[1] = 3         B[1] = 2      3
 * A[1] = 3         B[2] = 4      not possible
 * A[2] = 5         B[2] = 4      2
 * A[2] = 5         B[3] = 4      2
 * A[2] = 5         B[4] = 8      not possible
 * A[3] = 6         B[5] = 8      not possible
 * 
 * TOTAL count: 10
 * 
*/

#include <vector>
#include <iostream>
using namespace std;

int countInversionsInTwoSortedArrays(vector<int>& arr1, vector<int>& arr2) {

   int i = 0;
   int j = 0;
   int count = 0;
   int length1 = arr1.size();
   int length2 = arr2.size();

   while(i<length1 && j<length2) {

      if(arr1[i]<=arr2[j]) { // no inversion, move to next
         ++i;
         continue;
      }

      count = count + (length1-i);
      ++j;

   }

}

int main() {

   vector<int> arr1 {2, 3, 5, 6};
   vector<int> arr2 {2, 2, 4, 4, 8};

   cout<< countInversionsInTwoSortedArrays(arr1, arr2) << "\n";

   return 0;
}

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
*/