

/**
 * 
 * Left child of i-th node :  2i + 1
 * Right child of i-th node:  2i + 2
 * Parent of i-th node:      (i-1)/2
 * 
 * Queues, stacks, trees, graphs are all abstract data types. 
 * They represent an idea of storing and handling data.
 * For eg. queues represent the idea of storing data in a linear manner,
 * and handling enqueue and dequeue operations in FIFO fashion.
 * 
 * But the underlying data structure used for the implementation of a 
 * queue could be a linked list or a static array.
 * 
 * Similarly, a priority queue is an abstract data type that represents
 * the idea of storing of comparable data on basis of a defined priority.
 * The element with the greatest priority maybe removed from the colleciton.
 * 
 * And binary heap is a specific data structure which is most commonly used
 * for the implementation of a priority queue.
 * 
 * Other efficient ways of implementing a priority queue:
 *  • Binary search tree (may have bad performance in worst time 
 *    if the tree is skewed or highly unbalanced)
 *  • Self balancing binary search tree
 *  • Skip list
 *  • Fibonacci heap
 * 
 * Types of binary trees:
 * 
 * 1. Full binary tree
 *    Each child has either zero or two children
 * 
 * 2. Complete binary tree
 *    Each level is completely filled. The last level may be
 *    incompletely filled with nodes filled from the left side
 *    Eg. Heap
 * 
 * 3. Perfect binary tree
 *    All nodes have two children except the leaf nodes, and
 *    all the leaf nodes are at the same level
 * 
 * 4. Balanced binary tree
 *    The height of the left and the right subtrees of each node
 *    may vary by atmost 1
 *    The height of the tree is logN where N is the no of nodes
 *    Eg. AVL tree, Red black tree
 * 
 * 5. Degenerate binary tree
 *    Every node has a single child (linked list type structure)
 * 
 * 6. Skewed binary tree
 *    Every node has single child, either only the left or only the right
 *    (special type of degenerate binary tree)
 * 
*/