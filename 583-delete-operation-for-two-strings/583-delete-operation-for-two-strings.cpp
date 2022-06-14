class Solution {
public:
    
    int helper(string word1, string word2, int**dp){
        if(word1.size()==0 || word2.size()==0)  return max(word1.size(), word2.size());
        
        if(word1[0] == word2[0]){
            return helper(word1.substr(1), word2.substr(1), dp);
        }
        
        if(dp[word1.size()][word2.size()] != -1)    return dp[word1.size()][word2.size()];
        
        int p1 = 1+ helper(word1.substr(1), word2, dp);
        int p2 = 1+ helper(word1, word2.substr(1), dp);
        
        dp[word1.size()][word2.size()] = min(p1, p2);
        return min(p1, p2);
    }
    
    int minDistance(string word1, string word2) {
        int** dp = new int*[word1.size()+1];
        for(int i = 0; i <= word1.size(); i++){
            dp[i] = new int[word2.size()+1];
            for(int j = 0; j <= word2.size(); j++)
                dp[i][j] = -1;
        }
        
        int ans = helper(word1, word2, dp);
        
        for(int i = 0; i <= word1.size(); i++){
            delete[] dp[i];
        }
        delete[] dp;
        
        return ans;
    }
};