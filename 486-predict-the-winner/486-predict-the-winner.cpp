class Solution {
public:
    bool helper(vector<int>& nums, int start, int end, int a, int b){
        if(start > end){
            if(a >= b)  return true;
            else        return false;
        } else if(start == end){
            a += nums[start];
            if(a >= b)  return true;
            else        return false;
        }
        
        a += nums[start];
        bool p1 = helper(nums, start+2, end, a, b+nums[start+1]) & helper(nums, start+1, end-1, a, b+nums[end]);
        // if(p1)  return true;
        
        a -= nums[start];
        a += nums[end];
        bool p2 = helper(nums, start+1, end-1, a, b+nums[start]) & helper(nums, start, end-2, a, b+nums[end-1]);
        if(p1||p2)  return true;
        
        return false;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1, 0, 0);
    }
};