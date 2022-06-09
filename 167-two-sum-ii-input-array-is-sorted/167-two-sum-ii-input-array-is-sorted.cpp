class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, pair<int, int>> mp;
        for(int i = 0; i < numbers.size(); i++){
            pair<int, int> p;
            p.first = i; p.second = 1;
            mp[numbers[i]] = p;
        }
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++){
            int x = numbers[i];
            int t = target - x;
            auto it = mp.find(t);
            if(it != mp.end()){
                ans.push_back(i+1);
                ans.push_back((it->second.first)+1);
                break;
            }
        }
        
        return ans;
    }
};