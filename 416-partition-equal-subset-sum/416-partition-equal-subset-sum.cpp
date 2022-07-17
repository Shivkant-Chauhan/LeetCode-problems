class Solution {
public:
    int dp[20000];
    bool helper(vector<int>& nums, int sum, int id, int currSum){
        if(id == nums.size()){
            if(sum == currSum)  return true;
            return false;
        }
        
        if(dp[currSum] != -1){
            return dp[currSum];
        }
        
        bool p2 = helper(nums, sum, id+1, currSum + nums[id]);
        bool p1 = helper(nums, sum, id+1, currSum);
        
        
        return dp[currSum] = p1|p2;
    }
    
//     bool canPartition(vector<int>& nums) {
//         memset(dp, -1, sizeof(dp));
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if(sum&1)   return false;
        
//         return helper(nums, sum/2, 0, 0);
//     }

//bottom up..!!!
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1 || n == 1)   return false;
        sum /= 2;
        
//         sort(nums.begin(), nums.end());
        vector<bool> dp(sum+1, false);
        dp[0] = 1;
        
        
//         for(int k = 1; k <= sum; k++){
            
//         }
        
        
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= 0; j--){
                if(j >= nums[i]){
                    dp[j] = (dp[j] | dp[j-nums[i]]);
                }
            }
        }

        return dp[sum];
    }
    
};