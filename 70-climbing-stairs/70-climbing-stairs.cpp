class Solution {
public:
//     int helper(int n, int ans){
//         if(n < 0)   return 0;
//         if(n == 0)  return 1;
        
//         ans += helper(n-1, ans) + helper(n-2, ans);
//         return ans;
//     }
    
    int climbStairs(int n) {
        // return helper(n, 0);
        if(n < 2)   return 1;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};