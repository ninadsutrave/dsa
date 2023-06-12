#include <exception>
#include <unordered_map>
#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {

    private:
    struct BinaryTreeNode {
        T val;
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
    size_t currentSize;
    BinaryTreeNode* root;
    unordered_map<T,bool> isPresent;

    BinaryTreeNode* addNodeHelper(BinaryTreeNode* curr, int val) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = addNodeHelper(root->left, value);
        } else if (value > root->data) {
            root->right = addNodeHelper(root->right, value);
        }

        return root;
    }

    BinaryTreeNode* deleteNodeHelper(BinaryTreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNodeHelper(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNodeHelper(root->right, value);
        } else {
            if (root->left == nullptr) {
                BinaryTreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                BinaryTreeNode* temp = root->left;
                delete root;
                return temp;
            }

            BinaryTreeNode* min = getMinimumNode(root->right);
            root->data = min->data;
            root->right = deleteNodeHelper(root->right, min->data);
        }

        return root;
    }

    BinaryTreeNode* getMinimumNode(BinaryTreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    BinaryTreeNode* getMaximumNode(BinaryTreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    void inorderTraversalHelper(BinaryTreeNode* curr, vector<T>& traversal) {
        if (curr != nullptr) {
            inorderTraversalHelper(curr->left);
            traversal.push_back(curr->val)
            inorderTraversalHelper(curr->right);
        }
    }

    void preorderTraversalHelper(BinaryTreeNode* curr, vector<T>& traversal) {
        if (curr != nullptr) {
            traversal.push_back(curr->val)
            preorderTraversalHelper(curr->left);
            preorderTraversalHelper(curr->right);
        }
    }

    void postorderTraversalHelper(BinaryTreeNode* curr, vector<T>& traversal) {
        if (curr != nullptr) {
            postorderTraversalHelper(curr->left);
            postorderTraversalHelper(curr->right);
            traversal.push_back(curr->val)
        }
    }

    void destroyTree(BinaryTreeNode* root) {
        if (root != nullptr) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }

    public:
    BinarySearchTree() {
        root = nullptr;
        currentSize = 0;
    }
    ~BinarySearchTree() {
        destroyTree(root);
    }

    void addNode(int val) {

        if(isPresent[val]) {
            throw invalid_argument("Duplicate value addition");
        }

        isPresent[val] = true;
        root = addNodeHelper(root, val);

    }

    void removeNode(int val) {

        if(isPresent.find(val) == isPresent.end()) {
            return;
        }

        isPresent.erase(val);
        root = deleteNodeHelper(root, val);

    }

    T minValue() {
        BinaryTreeNode* minNode = getMinimumNode(root);
        return minNode->val;
    }

    T maxValue() {
        BinaryTreeNode* maxNode = getMaximumNode(root);
        return maxNode->val;
    }

    vector<T> inorderTraversal() {
        vector<T> traversal;
        inorderTraversalHelper(root, traversal);
        return traversal;
    }

    vector<T> preorderTraversal() {
        vector<T> traversal;
        preorderTraversalHelper(root, traversal);
        return traversal;
    }

    vector<T> postorderTraversal() {
        vector<T> traversal;
        postorderTraversalHelper(root, traversal);
        return traversal;
    }

    size_t size() {
        return currentSize;
    }

};

int main() {

    BinarySearchTree<int> bst;
    bst.addNode(50);
    bst.addNode(30);
    bst.addNode(20);
    bst.addNode(40);
    bst.addNode(70);
    bst.addNode(60);
    bst.addNode(10);

    cout<<bst.minValue()<<"\n";

    bst.removeNode(70);

    cout<<bst.size()<<"\n";
    cout<<bst.maxValue()<<"\n";

    vector<int> postorderTraversal = bst.postorderTraversal();
    for(int node: postorderTraversal) {
        cout<< node << " ";
    }

    return 0;
}