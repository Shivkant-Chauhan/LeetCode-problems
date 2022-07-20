class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> checker;
        int sum = 0;
        int ans = 0;
        checker[0]++;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int diff = sum - k;
            ans += checker[diff];
            checker[sum]++;
        }
        
        return ans;
    }
};