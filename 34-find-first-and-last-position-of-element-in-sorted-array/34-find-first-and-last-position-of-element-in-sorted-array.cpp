class Solution {
public:
    int helper(vector<int>& nums, int target, int x = 0){
        //if x is 10 then we will find its first occurence otherwise we will find its last occurence
        int ans = -1;
        int lo = 0, hi = nums.size();
        while(hi > lo){
            int m = (hi+lo) /2;
            if(nums[m] == target){
                ans = m;
                if(x == 10) hi = m;
                else        lo = m+1;
            } else if(nums[m] > target){
                hi = m;
            } else{
                lo = m+1;
            }
        }
        
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int p1 = helper(nums, target, 10);
        int p2 = helper(nums, target);
        
        ans[0] = p1;
        ans[1] = p2;
        return ans;
    }
};