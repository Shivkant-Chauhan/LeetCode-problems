class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> hsh;
        for(int i = 0; i < nums.size(); i++){
            hsh[nums[i]].push_back(i);
        }
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int p1 = 0, p2 = nums.size()-1;
        while(p1 < p2){
            long long sum = temp[p1] + temp[p2];
            if(sum == target){
                vector<int> output;
                auto it1 = hsh.find(temp[p1]);
                auto it2 = hsh.find(temp[p2]);
                if(it1 == it2){
                    output.push_back((it1->second)[0]);
                    output.push_back((it1->second)[1]);
                } else{
                    output.push_back((it1->second)[0]);
                    output.push_back((it2->second)[0]);    
                }
                return output;
            } else if(sum < target){
                p1++;
            } else{
                p2--;
            }
        }
        vector<int> o;
        o.push_back(-1);o.push_back(-1);
        return o;
    }
};