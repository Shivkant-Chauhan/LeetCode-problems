class Solution {
public:
//     int helper(vector<int>& nums, int pos, int ans, bool last){
//         if(last){
//             if(pos >= nums.size())      return ans;
//         } else{
//             if(pos >= nums.size()-1)    return ans;
//         }
        
//         ans += nums[pos];
//         int pass1 = helper(nums, pos+2, ans, last);
//         int pass2 = helper(nums, pos+3, ans, last);
        
//         return max(pass1, pass2);
//     }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);
        
//         int pass1 = helper(nums, 0, 0, false);
//         int pass2 = helper(nums, 1, 0, true);
//         int pass3 = helper(nums, 2, 0, true);
        
//         return max(pass1, max(pass2, pass3));
        
        int n = nums.size();
        int dp1[n];
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        dp1[2] = max(nums[1], nums[0]+nums[2]);
        
        for(int i = 3; i < n; i++){
            dp1[i] = nums[i]+ max(dp1[i-2], dp1[i-3]);
        }
        
        int output1 = INT_MIN;
        for(int i = 0; i < n-1; i++)  output1 = max(output1, dp1[i]);
        
        
        int dp2[n];
        dp2[0] = 0;
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        
        for(int i = 3; i < n; i++){
            dp2[i] = nums[i]+ max(dp2[i-2], dp2[i-3]);
        }
        
        int output2 = INT_MIN;
        for(int i = 1; i < n; i++)  output2 = max(output2, dp2[i]);
        
        
        return max(output1, output2);
    }
    
};