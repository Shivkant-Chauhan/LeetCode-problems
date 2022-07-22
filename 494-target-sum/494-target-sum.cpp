class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // this is simple variation of count of number of subsets with given difference
        // find the count of 2 subsets such that their difference is equsl to target!
        // and the sum of the 2 subsets is the total sum of given array
        
        // sum2 - sum1 = target
        // sum2 + sum1 = totalSum
        
        //=> sum2 = (target+totalSum)/2
        // find the count of the subsets having sum as sum2...
        
        int sumT = accumulate(nums.begin(), nums.end(), 0);
        if(target > sumT)   return 0;
        

        int dp[sumT+1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = sumT; j >= 0; j--){
                if(j - nums[i] >= 0){
                    dp[j] += dp[j-nums[i]];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i <= sumT; i++){
            if(dp[i] > 0){
                int x = (sumT - i);
                if((x - i) == target)    ans += dp[i];
            }
        }
        
        return ans;
    }
};