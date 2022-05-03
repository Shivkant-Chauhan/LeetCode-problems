class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even, odd;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]&1)   odd.push_back(nums[i]);
            else            even.push_back(nums[i]);
        }
            
        vector<int> output;
        for(int i = 0; i < even.size(); i++)    output.push_back(even[i]);
        for(int i = 0; i < odd.size(); i++)    output.push_back(odd[i]);
        
        return output;
    }
};