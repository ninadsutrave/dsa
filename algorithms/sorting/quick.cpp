/**
 * 
 * Quick sort works on the concept that, 
 * if for an element in the array, all elements before it are smaller,
 * and all elements after it are larger, then it is at its sorted position.
 * 
 * Best case time complexity: O(nlogn)
 * (achieved when pivot chosen is always the median)
 * 
 * Worst case time complexity: O(n^2)
 * (array is already sorted then pivot chosen is always at the beginning or end)
 * (results in very uneven partitions like of length n-1 and 1)
 * 
 * Average case time compleity: O(nlogn)
 * (choosing random pivot has expected complexity of nlogn)
 * 
 * Space complexity: O(n) stack size
 * 
 **/