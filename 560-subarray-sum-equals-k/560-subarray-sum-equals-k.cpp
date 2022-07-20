class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> checker;
        int sum = 0;
        int ans = 0;
        checker[0]++;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int diff = sum - k;
            auto it = checker.find(diff);
            if(it != checker.end()){
                ans += checker[diff];
                // if(sum==nums[i] && sum==diff){
                //     ans += checker[sum];
                // }
                // cout << i << " ";
            }
            checker[sum]++;
        }
        
        return ans;
    }
};