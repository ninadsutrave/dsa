/* https://leetcode.com/problems/house-robber-iii/ */
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

// returns the following pair for every node x
// (max sum if x was picked, max sum if x wasn't picked)

pair<int,int> getInclusiveAndExclusiveValues(BinaryTreeNode* node) {

    if(!node) {
        return make_pair(0, 0);
    }

    pair<int,int> leftChildSum = getInclusiveAndExclusiveValues(node->left);
    pair<int,int> rightChildSum = getInclusiveAndExclusiveValues(node->right);

    int includeNode = node->val + leftChildSum.second + rightChildSum.second;
    int excludeNode = max(leftChildSum.first, leftChildSum.second) + max(rightChildSum.first, rightChildSum.second);

    return make_pair(includeNode, excludeNode);
    
}

int maxValueRobbed(BinaryTreeNode* root) {

    pair<int,int> result;
    result = getInclusiveAndExclusiveValues(root);
    return max(result.first, result.second);

}

int main() {

    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(20);
    root->right = new BinaryTreeNode(9);
    root->left->left = new BinaryTreeNode(15);
    root->left->right = new BinaryTreeNode(7);
    root->left->left->right = new BinaryTreeNode(8);

    cout<<maxValueRobbed(root)<<"\n";
    return 0;
}

/**
 * 
 * Identify the subproblem. Max sum value in the entire tree,
 * is max value in left subtree + max value in right subtree + the root value(maybe)
 * subject to the given conditions. So apply these conditions
 * in a recursive fashion.
 * 
 * Approach:
 * For every node, calculate two sums: 
 *  1. Excluding the current node
 *  2. Including the current node
 * Thus every node returns a pair of values
 * (max sum if x was picked, max sum if x wasn't picked)
 * 
 * Let's call it (A, B)
 * 
 * There are no restriction in the case of 1. You may choose
 * the maximum sum values in the left and right subtrees and
 * simply sum them up to get the result
 * 
 * Result will be the maximum of the four cases:
 *  1. Aleft  +  Bleft
 *  2. Aright +  Bleft
 *  3. Aleft  +  Bright
 *  4. Aright +  Bleft
 * 
 * In case 2. we are enforcing the condition that current node
 * is selected. So in this case we have a restriction that neither
 * of the immediate children can be picked
 * 
 * Result will simply be: current + Bleft + Bright
 * 
 * Recursively return this as a pair again to solve the question.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(h) h -> height of the tree
*/