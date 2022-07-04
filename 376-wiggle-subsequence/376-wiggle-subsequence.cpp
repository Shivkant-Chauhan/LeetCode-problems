class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        
        vector<int> diff;
        for(int i = 1; i < nums.size(); i++){
            int d = nums[i] - nums[i-1];
            diff.push_back(d);
        }
        
        // 16 -12 5 3 5 -5 -5 11 -8
        int p1 = 0;
        int ans = 0;
        int temp = diff[p1++];
        bool flag = 0;
        if(temp == 0)   flag = 1;
        while(temp == 0 && p1 < diff.size()){
            temp = diff[p1++];
        }
        while(p1 < diff.size()){
            if(diff[p1] == 0){
                p1++;
                continue;
            }
            if(temp > 0){
                if(diff[p1] > 0){
                    temp = min(temp, diff[p1++]);
                } else{
                    temp = diff[p1++];
                    ans++;
                    if(flag){
                        flag = 0;
                    }
                }
            } else{
                if(diff[p1] < 0){
                    temp = max(temp, diff[p1++]);
                } else{
                    temp = diff[p1++];
                    ans++;
                    if(flag){
                        flag = 0;
                    }
                }
            }
        }
        
        if(flag)    ans--;
        return ans +2;
    }
};