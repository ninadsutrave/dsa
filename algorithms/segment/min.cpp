/**
 * 
 * Remember that if we only have to compute range sum queries
 * it can be done in O(1) / query using prefix sum array
 * sum(L,R) = prefix[R] - prefix[L]
 * But update operations will be O(n)
 *  
 * As for segment trees same logic can be used for:
 *  1. Range sum query
 *  2. Range max query
 *  3. Range GCD query 
 *  4. Range AND/OR/XOR query
 * 
*/