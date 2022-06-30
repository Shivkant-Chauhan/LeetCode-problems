class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        int val = nums[mid];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += (abs(nums[i] - val));
        }
        
        return ans;
    }
};