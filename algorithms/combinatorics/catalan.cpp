/**
 * Catalan Numbers
 * 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …  
 * 
 * Cn = (2n)!/n!(n+1)!
 * 
 * C0 = 1
 * Cn+1 = sum(Ci * Cn-i)
 * 
 * Applications:
 *  1. Number of possible binary search trees with n keys
 *  2. Number of balanced expressions containing n pairs of parantheses
 *     ((())), ()(()), ()()(), (())(), (()())
 *  3. Number of full binary trees with n nodes
 *  4. Number of binary strings such that no inital segment of string contains more 0s than 1s (Dyck words)
 *  5. Number of paths with 2n steps on a rectangular grid from bottom left that
 *     do not cross above the main diagonal
 *  6. Number of ways a convex polygon of n+2 sides can split into triangles by connecting vertices
 *  7. Number of mountain ranges with peaks and valleys such that range stays above the land
 * 
 *                                    /\
 *                /\   /\     /\/\   / \
 *     /\/\/\  /\/ \  / \/\  /   \  /  \
*/