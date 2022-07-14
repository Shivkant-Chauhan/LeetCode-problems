class Solution {
public:
    bool helper(vector<int>& nums, int n, int sum1, int sum2, int** dp){
        if(n == nums.size()){
            if(sum1 == sum2)    return true;
            else                return false;
        }
        
        if(dp[n][sum1] != -1)   return dp[n][sum1];
        
        bool p1 = helper(nums, n+1, sum1+nums[n], sum2, dp);
        bool p2 = helper(nums, n+1, sum1, sum2+nums[n], dp);
        
        return dp[n][sum1] = (p1 || p2);
    }

    bool canPartition(vector<int>& nums) {
        int** dp = new int*[nums.size()];
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++){
            dp[i] = new int[sum];
            for(int j = 0; j < sum; j++)
                dp[i][j] = -1;
        }
            
        return helper(nums, 0, 0, 0, dp);
    }
};