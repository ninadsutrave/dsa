/* https://leetcode.com/problems/find-median-from-data-stream/ */
#include <queue>
#include <iostream>
using namespace std;

class MedianFinder {

    private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    public:
    MedianFinder() {
        maxHeap = priority_queue<int>();
        minHeap = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void add(int num) {

        int minHeapSize = minHeap.size();
        int maxHeapSize = maxHeap.size();

        if(maxHeapSize == 0) {
            maxHeap.push(num); 
            return;
        } else if(num >= maxHeap.top()) {
            minHeap.push(num);
            ++minHeapSize;
        } else {
            maxHeap.push(num);
            ++maxHeapSize;
        }

        if(abs(minHeapSize - maxHeapSize) < 2) return;

        if(maxHeapSize > minHeapSize) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else if(maxHeap.size() < minHeap.size()) {
            return minHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top())/2.0;
        }

    }
};

int main() {

    MedianFinder mf;

    mf.add(5);
    cout<<mf.findMedian()<<"\n";
    mf.add(8);
    cout<<mf.findMedian()<<"\n";
    mf.add(-2);
    cout<<mf.findMedian()<<"\n";
    mf.add(3);
    cout<<mf.findMedian()<<"\n";
    mf.add(9);
    cout<<mf.findMedian()<<"\n";
    mf.add(0);
    cout<<mf.findMedian()<<"\n";
    mf.add(1);
    
    //  -2   0   1   3   5   8  9

    return 0;
}

/**
 * 
 * Median is - 
 *  either the middle element of a sorted distribution
 *  average of two middle elements of a sorted distribution
 * 
 * One solution could be by always maintaining a sorted order
 * at every insertion, which requires O(NlogN) complexity
 * 
 * But we must realise that the middle two elements are the
 * only elements that matter for calculating the median
 * 
 * So if we maintain two separate collections, one for the
 * bigger half of elements, and one for the smaller half, we
 * can get the median quickly 
 * 
 * So we maintain two heaps. One max heap to store the smaller
 * elements (so that we can retrieve the largest among them quickly)
 * and one min heap for the larger elements (so that we can retrieve 
 * the smallest among them quickly)
 * 
 * At all times we will ensure the difference in the sizes of the heaps
 * is atmost one (in case of odd number of elements) or is zero
 * (in case of even number of elements)
 * 
 * add(num)     - O(logn) 
 * findMedian() - O(1)
 * 
*/