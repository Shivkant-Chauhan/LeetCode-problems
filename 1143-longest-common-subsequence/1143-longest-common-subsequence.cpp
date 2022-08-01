class Solution {
public:
//     int dp[1010][1010];
//     int helper(string x, string y, int id1, int id2){
//         if(id1==x.size() || id2==y.size())  return 0;
        
//         if(dp[id1][id2] != -1)  return dp[id1][id2];
        
//         if(x[id1] == y[id2]){
//             return dp[id1][id2] = 1+ helper(x, y, id1+1, id2+1);
//         } else{
//             int p1 = helper(x, y, id1+1, id2);
//             int p2 = helper(x, y, id1, id2+1);
            
//             return dp[id1][id2] = max(p1, p2);
//         }
//     }
    
    int longestCommonSubsequence(string x, string y) {
        // memset(dp, -1, sizeof dp);
        // return helper(x, y, 0, 0);
        
        int m = x.size(), n = y.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof dp);
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else{
                    int p1 = dp[i-1][j];
                    int p2 = dp[i][j-1];
                    
                    dp[i][j] = max(p1, p2);
                }
            }
        }
        
        return dp[m][n];
    }
    
//     int helper(string x, string y, int id1, int id2){
//         if(!id1 || !id2)    return 0;
//         if(dp[id1][id2] != -1)  return dp[id1][id2];
        
//         if(x[id1-1] == y[id2-1]){
//             return dp[id1][id2] = 1+ helper(x, y, id1-1, id2-1);
//         } else{
//             int p1 = helper(x, y, id1-1, id2);
//             int p2 = helper(x, y, id1, id2-1);
            
//             return dp[id1][id2] = max(p1, p2);
//         }
//     }
  
//     int longestCommonSubsequence(string text1, string text2){
//         memset(dp, -1, sizeof dp);
//         return helper(text1, text2, text1.size(), text2.size());
//     }
    
};