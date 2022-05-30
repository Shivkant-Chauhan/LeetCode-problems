class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size();
        
        map<char, vector<int>> hsh;
        for(int i = 0; i < s.size(); i++)
            hsh[s[i]].push_back(i);
        
        for(int i = 0; i < s.size(); i++){
            vector<int> temp = hsh[s[i]];
            auto id = upper_bound(temp.begin(), temp.end(), i);
            while(id != temp.end()){
                string s1 = s.substr(i, *id-i+1);
                string s2 = s1;
                reverse(s2.begin(), s2.end());
                
                if(s1 == s2) ans++;
                id++;
            }
        }
        
        return ans;
    }
};