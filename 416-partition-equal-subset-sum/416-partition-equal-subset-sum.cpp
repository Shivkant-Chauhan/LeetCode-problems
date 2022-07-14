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
    
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)   return false;
        
        return helper(nums, sum/2, 0, 0);
    }
};
    // int dp[20000];
    // bool sol(vector<int>& nums, int t, int i=0, int s=0) {
    //     int n=nums.size();
    //     if(i>=n) {
    //         if(s==t) return true;
    //         else return false;
    //     } 
    //     if(dp[s]!=-1) return dp[s];
    //     bool res = false;
    //     res |= sol(nums, t, i+1, s+nums[i]);
    //     res |= sol(nums, t, i+1, s);
    //     return dp[s]=res;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     if(sum&1) return false;
    //     int t = sum/2;
    //     memset(dp, -1, sizeof dp);
    //     return sol(nums, t);
    // }
// };