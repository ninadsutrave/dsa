#include <iostream>
#include <vector>
using namespace std;

void generateParantheses(string curr, int n, int open, int closed, vector<string>& result) {

    if(closed>open || open>n) {
        return;
    }

    if(open == n && closed == n) {
        result.push_back(curr);
        return;
    }

    curr.push_back('(');
    generateParantheses(curr, n, open+1, closed, result);
    curr.pop_back(); // backtracking

    curr.push_back(')');
    generateParantheses(curr, n, open, closed+1, result);
    curr.pop_back(); // backtracking

}

int main() {

    int n = 5;
    string curr = "";
    vector<string> result;
    generateParantheses(curr, n, 0, 0, result);

    for(string str: result) {
        cout<<str<<"\n";
    }

    return 0;
}

/**
 * 
 * Time Complexity: O()
 * Space Complexity: O(n) 
 * 
 * Number of balanced expressions containing n pairs of parantheses
 * is the nth Catalan number
 * Cn = (2n)!/n!(n+1)!
 * 
 * For any prefix of the string:
 *  1. Number of open and closed brackets mustn't exceed n
 *  2. Number of closed brackets mustn't exceed number of open brackets
 * 
 * Generate all possible combinations, and backtrack in case of 1 and 2
 * 
 * Same approach can be used to print all Dyck words on length 2n
 * Dyck word - Binary strings such that no prefix contains more 0s than 1s 
 * 
*/