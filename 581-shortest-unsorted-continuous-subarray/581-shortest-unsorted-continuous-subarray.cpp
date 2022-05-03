class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int start = -1, end = -1;
        int p1 = 0;
        while(p1 < nums.size()){
            if(nums[p1] != temp[p1]){
                start = p1;
                break;
            }
            p1++;
        }
        
        if(start == -1) return 0;
        p1 = nums.size()-1;
        while(p1 > start){
            if(nums[p1] != temp[p1]){
                end = p1;
                break;
            }
            p1--;
        }
        
        return end - start +1;
//         int start = -1;
//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] < nums[i-1]){
//                 start = i-1;
//                 break;
//             }
//         }
//         if(start == -1) return 0;
//         int end = start+1;
//         for(int i = start+1; i < nums.size(); i++){
//             if(nums[i]<nums[i-1] && nums[i]>nums[start])
//                 end = i;
//         }
        
//         cout << start << " " << end;
//         return end-start+1;
    }
};