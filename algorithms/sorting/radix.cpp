/**
 *   Time Complexity: O(nk)
 *   n: number of elements
 *   k: average number of digits
 * 
 *   Limitations:
 *   Radix sort requires a significant amount of extra space to store intermediate results during each pass. 
 *   The space complexity is proportional to the input size and the range of values.
 *   It is primarily applicable to sorting integers or fixed-length strings. 
 *   Sorting variable-length strings or other complex data types may require additional preprocessing steps.
 *   Radix sort is not a comparison-based algorithm, so it cannot be directly applied to sort elements based on custom comparison functions.
 *
 *   Suitable Cases:
 *   Radix sort is well-suited for sorting large arrays of integers or fixed-length strings with a relatively small range of values.
 *   When the size of the input data is significantly larger than the range of values, radix sort can be more efficient than comparison-based sorting algorithms.
 *   It is useful when stability (preserving the relative order of equal elements) is required since radix sort inherently maintains stability.
 **/