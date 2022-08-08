// class Solution {
// public:
//     int dp[3000][3000];
    
//     int helper(vector<int>& nums, int id, int prev){
//         if(id == nums.size())   return 0;
        
//         if(dp[id][prev+1] != -1)    return dp[id][prev+1];
        
//         int p1 = INT_MIN, p2 = INT_MIN;
//         if(prev == -1 || nums[id] > nums[prev]){
//             p1 = 1+ helper(nums, id+1, id);
//         }
//         p2 = helper(nums, id+1, prev);
//         return dp[id][prev+1]=max(p1, p2);
//     }
        
//     int lengthOfLIS(vector<int>& nums) {
//         memset(dp, -1, sizeof dp);
//         return helper(nums, 0, -1);
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int ans = 0;
//         int n =nums.size();
//         vector<int> dp(n, 1);
        
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if(nums[j] > nums[i]) {
//                     dp[j] = max(dp[j], dp[i]+1);
//                 }
//             }
//         }
        
//         for(int x : dp) {
//             ans = max(ans, x);
//         }
//         return ans;
        
//     }
// };





// nlogn solution:

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> sub;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            auto it = lower_bound(sub.begin(), sub.end(), nums[i]);
            if(it != sub.end()) {
                *it = nums[i];
            } else {
                sub.push_back(nums[i]);
            }
        }
        return sub.size();
    }
};