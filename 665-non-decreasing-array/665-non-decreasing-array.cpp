class Solution {
public:
    
    bool checkPossibility(vector<int>& nums) {    
        if(nums.size() < 3)
            return true;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                bool flag = true;
                for(int z = 1; z < i; z++){
                    if(nums[z]<nums[z-1]){
                        flag = false;
                        break;
                    }
                }
                for(int z = i+2; z < nums.size(); z++){
                    if(nums[z] < nums[z-1]){
                        flag = false;
                        break;
                    }
                }
                if(i<nums.size()-1 && nums[i+1] < nums[i-1])   flag = false;
                if(flag)    return true;

                flag = true;
                for(int z = 1; z < i-1; z++){
                    if(nums[z] < nums[z-1]){
                        flag = false;
                        break;
                    }
                }
                for(int z = i+1; z < nums.size(); z++){
                    if(nums[z] < nums[z-1]){
                        flag = false;
                        break;
                    }
                }

                if(i>1 && nums[i] < nums[i-2]) flag = false;
                if(flag)    return true;
                else        return false;
            }
        }
        
        return true;
    }
};