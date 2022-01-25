class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int hsh[len+1][2];
        // hsh[0][0] = 0;
        for(int i = 0; i <= len; i++){
            for(int j = 0; j < 2; j++)
                hsh[i][j] = 0;
        }
        for(int i = 0; i < len; i++){
            int temp = nums[i];
            if(temp < 0){
                hsh[temp][1]++;
                if(hsh[temp][1] == 2)
                    return temp;
            }
            else{
                hsh[temp][0]++;
                // cout << hsh[temp][0];
                if(hsh[temp][0] == 2)
                    return temp;
            }
        }
        
        return -1;
    }
};