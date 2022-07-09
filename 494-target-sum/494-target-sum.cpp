class Solution {
public:
    int dp[25][2500];
    int helper(vector<int>& nums, int n, int sum, int target){
        if(n == nums.size()){
            if(sum == target)
                return 1;
            else
                return 0;
        }
        
        if(dp[n][sum+1000] != -1){
            return dp[n][sum+1000];
        }
        
        int pass1 = helper(nums, n+1, sum+nums[n], target);
        int pass2 = helper(nums, n+1, sum-nums[n], target);
        
        return dp[n][sum+1000] = (pass1+pass2);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0, 0, target);
    }
};