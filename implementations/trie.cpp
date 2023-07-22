/* fix bug in delete word */

#include <iostream>
#include <vector>
using namespace std;

class Trie {

    private:
    struct TrieNode {
        vector< TrieNode* > next;
        bool endOfWord;
        int children;

        TrieNode() {
            next.resize(26);
            endOfWord = false;
            children = 0;
        }
    };
    TrieNode* root;

    void clear(TrieNode* node) {

        if (node == nullptr) return;

        for (TrieNode* nextNode : node->next) {
            clear(nextNode);
        }

        delete node;
    }

    bool deleteNodes(TrieNode* node, string word, int depth) {

        if (depth == word.length()) {
            if (!node->endOfWord) return false;
            node->endOfWord = false;
            return (node->children == 0);
        }

        char ch = word[depth];
        if (!node->next[ch - 'a']) return false;

        TrieNode* nextNode = node->next[ch - 'a'];
        bool deleteChildNode = deleteNodes(nextNode, word, depth + 1);

        if (deleteChildNode) {
            delete nextNode;
            --(node->children);
            return (node->children == 0);
        }

        return false;

    }

    public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void insert(string word) {

        TrieNode* node = root;

        for(char ch: word) {
            if(!node->next[ch - 'a']) { // if this letter doesn't exist as a child, create one
                node->next[ch - 'a'] = new TrieNode(); 
                ++(node->children);
            }
            node = node->next[ch - 'a'];
        }

        node->endOfWord = true;

    }

    bool search(string word) {

        TrieNode* node = root;

        for(char ch: word) {
            if(!node->next[ch - 'a']) { // if this letter doesn't exist as a child, return false
                return false;
            }
            node = node->next[ch - 'a'];
        }

        return node->endOfWord;

    }

    bool startsWith(string prefix) {

        TrieNode* node = root;

        for(char ch: prefix) {
            if(!node->next[ch - 'a']) { // if this letter doesn't exist as a child, return false
                return false;
            }
            node = node->next[ch - 'a'];
        }
        
        return true;

    }

    void remove(string word) {
        deleteNodes(root, word, 0);
    }

};

int main () {

    Trie T;
    T.insert("plant");
    T.insert("prank");
    T.insert("table");
    T.insert("placenta");
    T.insert("tabular");
    T.insert("tabloids");
    T.insert("placement");

    cout<<T.search("apple")<<"\n";
    cout<<T.search("tabloids")<<"\n";
    cout<<T.search("tabloid")<<"\n";
    cout<<T.search("prank")<<"\n";

    T.remove("prank");
    T.remove("plant");

    cout<<T.startsWith("pla")<<"\n";
    cout<<T.startsWith("tabo")<<"\n";
    cout<<T.startsWith("pr")<<"\n";
    cout<<T.startsWith("cha")<<"\n";


    return 0;
}

/**
 * 
 * Trie data structure (also known as prefix trees or digital trees) is an advanced 
 * data structure used for storing and searching strings efficiently
 * 
 * Trie comes from the word reTRIEval
 * 
 * It is basically creates n-ary tree for the dictionary given to us where each tree node
 * is formed from the character of each word. 
 * 
 * For a word of size n:
 * insert       : O(n)
 * search       : O(n)
 * startsWith   : O(n)
 * remove       : O(n)
 * 
 * Space complexity of the entire trie structure:
 * 
 * O(N * L)
 * where N is the number of unique first letters in all the inserted words and L is the length of the longest word
 * 
 * Advantages over a hash table:
 * • Prefix-based searching can't be done with a hash table
 * • The efficiency of a hash table heavily relies on the quality of the hash function and the avoidance of collisions
 * • Hash functions are not used in a Trie data structure, so it is quicker
 * 
 * Disadvantages:
 *  • The main disadvantage of the trie is that it takes a lot of memory to store all the strings
 *    For each node, we have too many node pointers which are equal to the no of characters in the worst case
 * 
 *  • An efficiently constructed hash table (i.e. a good hash function and a reasonable load factor) has 
 *    O(1) as lookup time which is way faster than O(l) in the case of a trie, where l is the length of the string
 * 
 * Applications:
 * • Generating text suggestions
 * • Spell check and auto correct
 * 
 * Other wide variety of applications in data compression, computational biology, longest prefix matching 
 * algorithm used for routing tables for IP addresses 
 * 
*/