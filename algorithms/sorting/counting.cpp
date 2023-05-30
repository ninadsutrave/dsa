/*
 * Time Complexity: O(n + k)
 * n: number of elements
 * k: range of input values
 * 
 * Limitations:
 * Counting sort has a limited range of applicability. 
 * It can only be used to sort non-negative integers or elements that can be mapped to non-negative integers.
 * The space complexity of counting sort is proportional to the range of input values, 
 * making it less efficient when the range is significantly larger than the number of elements.
 * If the range of values is too large, counting sort may become impractical due to memory constraints. * 

 * Suitable Cases:
 * Counting sort is an excellent choice when the range of input values is small and known in advance.
 * It is highly efficient for sorting arrays with a relatively small range of non-negative integers.
 * When stability is important and the input values fall within a limited range, counting sort can be a preferred sorting algorithm.
 * 
*/