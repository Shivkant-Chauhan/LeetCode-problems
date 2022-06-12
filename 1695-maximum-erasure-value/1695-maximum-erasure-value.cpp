class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 1)    return nums[0];
        
        int p1 = 0, p2 = 0;
        int ans = -1;
        int score = 0;
        map<int, int> hsh;
        while(p1 < nums.size()){
            while(p1<nums.size() && hsh[nums[p1]]==0){
                score += nums[p1];
                hsh[nums[p1]]++;
                p1++;
            }
            ans = max(ans, score);
            if(p1 >= nums.size())   break;
            while(p1>p2 && hsh[nums[p1]]>0){
                score -= nums[p2];
                hsh[nums[p2]]--;
                p2++;
            }
        }
        
        return ans;
    }
};