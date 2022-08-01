class Solution {
public:
//   int dp[110][110];
//     int helper(int r, int c, int m, int n){
//         if(r == m-1 && c == n-1){
//             return 1;
//         }
        
//         if(r >= m || c >= n)    return 0;
        
//         if(dp[r][c] != -1){
//             return dp[r][c];
//         }
        
//         int p1 = helper(r+1, c, m, n);
//         int p2 = helper(r, c+1, m, n);
//         return dp[r][c] = (p1+p2);
//     }
    
//     int uniquePaths(int m, int n) {
//         memset(dp, -1, sizeof dp);
//         return helper(0, 0, m, n);
//     }
    
    int uniquePaths(int m, int n){
        int dp[m][n];
        memset(dp, 0, sizeof dp);
        dp[m-1][n-1] = 1;

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int x = 0, y = 0;
                if(i+1 < m) x = dp[i+1][j];
                if(j+1 < n) y = dp[i][j+1];
                dp[i][j] = max(dp[i][j], x+y);
            }
        }
        
        return dp[0][0];
    }
        
};