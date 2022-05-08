class Solution {
public:
//     int helper(vector<int>& nums, int pos, int ans){
//         if(pos >= nums.size())  return ans;
        
//         ans += nums[pos];
//         int pass1 = helper(nums, pos+2, ans);
//         int pass2 = helper(nums, pos+3, ans);
        
//         return max(pass1, pass2);
//     }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 1)    return nums[0];
        if(n == 2)  return max(nums[0], nums[1]);
        // return helper(nums, 0, 0);
        
        int dp[n+1];
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = nums[1];
        for(int i = 3; i <= n; i++){
            dp[i] = nums[i-1] + max(dp[i-2], dp[i-3]);
        }
        
        int ans = INT_MIN;
        for(auto &i : dp)   ans = max(ans, i);
        return ans;
    }
};