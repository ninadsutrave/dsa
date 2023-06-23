#include <iostream>
#include <cmath>
using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    BinaryTreeNode(int data) {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

int getMaxSum(BinaryTreeNode* root, int& currMax) {

    if(root == NULL) return 0;

    int leftMax = max(0, getMaxSum(root->left, currMax));
    int rightMax = max(0, getMaxSum(root->right, currMax));

    // calculate the max sum in left and right subtrees, but 
    // if it is less than 0 don't consider it (taking max with 0)

    return max(currMax, root->val + leftMax + rightMax);

}

int calculate(BinaryTreeNode* root) {

    if (root == NULL) return 0;

    int result = INT_MIN;
    return getMaxSum(root, result);

}

int main() {

    BinaryTreeNode* root = new BinaryTreeNode(-5);
    root->left = new BinaryTreeNode(20);
    root->right = new BinaryTreeNode(9);
    root->left->left = new BinaryTreeNode(15);
    root->left->right = new BinaryTreeNode(7);
    root->left->left->right = new BinaryTreeNode(8);

    cout<<calculate(root)<<"\n";
    cout<<calculate(root->left)<<"\n";

    return 0;
}

/**
 * Think about it! 
 * Let's say you find the path which has the maximum sum, 
 * it is guaranteed to fall under one of the following three cases.
 * 
 *  1. A central node is there on the path, there are some nodes in the 
 *     central node's right subtree in the path with a positive sum, and 
 *     some nodes in the central node's left subtree with a positive sum
 *     (important to note that each path nodes in the children have a 
 *      positive sum, because if they didn't it is optimal to skip them)
 * 
 *  2. There is a starting node on the path, and the path entirely continues
 *     only in the starting node's right subtree 
 *     (this will happen when no node paths on the left give a positive sum)
 * 
  * 3. There is a starting node on the path, and the path entirely continues
 *     only in the starting node's left subtree 
 *     (this will happen when no node paths on the right give a positive sum)
 * 
 * So consider all these cases, and maintain the maximum of these three
 * 
 * Time Complexity: O(n)
 * Space Complexity O(h) h-> height of the tree
*/