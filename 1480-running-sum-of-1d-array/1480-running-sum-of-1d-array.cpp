class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> pf;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            k += nums[i];
            pf.push_back(k);
        }
        
        return pf;
    }
};