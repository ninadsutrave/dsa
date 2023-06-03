#include <exception>
#include <unordered_map>
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

    BinaryTreeNode* getMinimumNode(BinaryTreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    public:
    BinarySearchTree() {
        root = nullptr;
        currentSize = 0;
    }

    void addNode(int val) {

        if(isPresent[val]) {
            throw invalid_argument("Duplicate value addition");
        }

        isPresent[val] = true;
        root = addNodeHelper(root, val);

    }

    void removeNode(int val) {

        if(!isPresent[val]) {
            return;
        }

        isPresent[val] = true;
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

    size_t size() {
        return currentSize;
    }


    

};