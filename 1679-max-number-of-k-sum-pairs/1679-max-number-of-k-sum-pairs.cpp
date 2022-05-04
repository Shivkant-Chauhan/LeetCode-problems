class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int p1 = 0, p2 = temp.size()-1;
        int output = 0;
        while(p1 < p2){
            int sumTemp = temp[p1] + temp[p2];
            if(sumTemp > k)         p2--;
            else if(sumTemp < k)    p1++;
            else{
                output++;
                p1++;
                p2--;
            }
        }
        
        return output;
    }
};