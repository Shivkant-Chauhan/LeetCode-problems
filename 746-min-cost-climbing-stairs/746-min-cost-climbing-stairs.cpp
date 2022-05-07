class Solution {
public:
//     int helper(vector<int>& cost, int pos, int ans){
//         int n = cost.size();
//         if(pos >= n)  return ans;
        
//         ans += cost[pos];
        
//         int val1 = helper(cost, pos+1, ans);
//         int val2 = helper(cost, pos+2, ans);
        
//         return min(val1, val2);
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(helper(cost, 0, 0), helper(cost, 1, 0));
        int n = cost.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; i++){
            dp[i] = min(cost[i-1]+dp[i-1], cost[i-2]+dp[i-2]);
        }
        // for(auto &i : dp)   cout << i << " ";
        
        return dp[n];
    }
};