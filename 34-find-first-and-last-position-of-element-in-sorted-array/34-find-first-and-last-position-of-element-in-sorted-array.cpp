class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int p1 = -1, p2 = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                p2 = i;
                if(p1 == -1)    p1 = i;
            }
        }
        vector<int> ans(2);
        ans[0] = p1;
        ans[1] = p2;
        
        return ans;
    }
};