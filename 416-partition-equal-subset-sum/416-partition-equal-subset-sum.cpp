class Solution {
public:
    int dp[200][20000];
    bool helper(vector<int>& nums, int sum, int id, int currSum){
        if(id == nums.size()){
            if(sum == currSum)  return true;
            return false;
        }
        
        if(dp[id][currSum] != -1){
            return dp[id][currSum];
        }
        
        bool p1 = helper(nums, sum, id+1, currSum);
        bool p2 = helper(nums, sum, id+1, currSum + nums[id]);
        
        return dp[id][currSum] = p1|p2;
    }
    
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)   return false;
        
        return helper(nums, sum/2, 0, 0);
    }
};