class Solution {
public:
//     int dp[201][1001];
//     int helper(vector<int>& nums, int id, int target){
//         if(target == 0) return 1;
//         if(target < 0)  return 0;
//         if(id == 0)     return 0;
        
//         if(dp[id][target] != -1)    return dp[id][target];
        
//         int p1 = helper(nums, id-1, target);
//         int p2 = helper(nums, nums.size(), target-nums[id-1]);
//         return dp[id][target] = (p1+p2);
//     }
    
    int combinationSum4(vector<int>& nums, int target) {
        // memset(dp, -1, sizeof dp);
        // return helper(nums, nums.size(), target);
        int n = nums.size();
        long long dp[target+1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 0; i <= target; i++){
            for(int j = 0; j < n; j++){
                if(i-nums[j] >= 0){
                    dp[i] = (dp[i]+dp[i-nums[j]])%1000000000000000007;
                }
            }
        }
        
        return dp[target];
    }
};