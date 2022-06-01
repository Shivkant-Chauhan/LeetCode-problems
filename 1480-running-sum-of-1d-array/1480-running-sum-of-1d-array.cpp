class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> hsh;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            k += nums[i];
            hsh.push_back(k);
        }
        
        return hsh;
    }
};