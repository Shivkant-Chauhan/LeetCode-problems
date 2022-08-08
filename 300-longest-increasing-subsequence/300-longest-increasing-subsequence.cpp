class Solution {
public:
    int dp[3000][3000];
    
    int helper(vector<int>& nums, int id, int prev){
        if(id == nums.size())   return 0;
        
        if(dp[id][prev+1] != -1)    return dp[id][prev+1];
        
        int p1 = INT_MIN, p2 = INT_MIN;
        if(prev == -1 || nums[id] > nums[prev]){
            p1 = 1+ helper(nums, id+1, id);
        }
        p2 = helper(nums, id+1, prev);
        return dp[id][prev+1]=max(p1, p2);
    }
        
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return helper(nums, 0, -1);
    }
};