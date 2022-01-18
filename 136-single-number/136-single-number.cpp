class Solution {
public:
    int singleNumber(vector<int>& nums) {
//         const int size = 1e5;
//         int hsh[size];
//         hsh[0] = 0;
        
        int len = nums.size();
        if(len == 1){
            return nums[0];
        }
        int ans = 0;
        for(int i = 0; i < len; i++){
            // hsh[nums[i]]++;
            ans = ans^nums[i];
        }
        // for(int i = 0; i < size; i++){
        //     if(hsh[i] == 1){
        //         return i;
        //     }
        // }
    return ans;
    }
};