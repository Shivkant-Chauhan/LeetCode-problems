class Solution {
public:
    int dp[110][110];
    int helper(int r, int c, int m, int n){
        if(r == m-1 && c == n-1){
            return 1;
        }
        
        if(r >= m || c >= n)    return 0;
        
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        
        int p1 = helper(r+1, c, m, n);
        int p2 = helper(r, c+1, m, n);
        return dp[r][c] = (p1+p2);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof dp);
        return helper(0, 0, m, n);
    }
};