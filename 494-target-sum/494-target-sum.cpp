class Solution {
public:
    int helper(vector<int>& nums, int n, int sum, int target){
        if(n == nums.size()){
            if(sum == target)
                return 1;
            else
                return 0;
        }
        
        int pass1 = helper(nums, n+1, sum+nums[n], target);
        int pass2 = helper(nums, n+1, sum-nums[n], target);
        
        return (pass1+pass2);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0, 0, target);
    }
};