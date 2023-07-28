/* https://leetcode.com/problems/decremental-string-concatenation/?envType=list&envId=rruvl2f2 */

int getSmallestLength(vector<string>& words, vector<vector<vector<int>>>& dp, int index, char first, char last) {
    
    if(index == words.size()) return 0;
    
    if(dp[index][first - 'a'][last - 'a'] != -1) return dp[index][first - 'a'][last - 'a'];
    
    int size = words[index].length();

    vector<int> next(2, size);

    if(words[index][0] == last) {
        --next[0];
    }

    if(words[index][size-1] == first) {
        --next[1];
    }

     return dp[index][first - 'a'][last - 'a'] = 
            min(
                next[0] + getSmallestLength(words, dp, index+1, first, words[index][size-1]),
                next[1] + getSmallestLength(words, dp, index+1, words[index][0], last)
            );
}

int minimizeConcatenatedLength(vector<string>& words) {
    int size = words.size();
    vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(26, vector<int>(26,-1)));
    
    int length = words[0].length();
    return length + getSmallestLength(words, dp, 1, words[0][0], words[0][length-1]);
}