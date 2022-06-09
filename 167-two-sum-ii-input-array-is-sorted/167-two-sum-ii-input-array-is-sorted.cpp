class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size()-1;
        vector<int> ans;
        while(p1 < p2){
            int v1 = numbers[p1], v2 = numbers[p2];
            int sum = v1 + v2;
            if(sum > target){
                p2--;
            } else if(sum < target){
                p1++;
            } else{
                ans.push_back(p1+1);
                ans.push_back(p2+1);
                break;
            }
        }
        
        return ans;
        
//         map<int, pair<int, int>> mp;
//         for(int i = 0; i < numbers.size(); i++){
//             pair<int, int> p;
//             p.first = i; p.second = 1;
//             mp[numbers[i]] = p;
//         }
//         vector<int> ans;
//         for(int i = 0; i < numbers.size(); i++){
//             int x = numbers[i];
//             int t = target - x;
//             auto it = mp.find(t);
//             if(it != mp.end()){
//                 ans.push_back(i+1);
//                 ans.push_back((it->second.first)+1);
//                 break;
//             }
//         }
        
//         return ans;
    }
};