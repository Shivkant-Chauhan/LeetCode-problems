class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.size();
        
        for(int i = 0; i < s.size(); i++){
            int k1 = i, k2 = i+1;
            while(k1>=0&&k2<s.size() && s[k1--]==s[k2++])   ans++;
            
            k1 = i-1;
            k2 = i+1;
            while(k1>=0&&k2<s.size() && s[k1--]==s[k2++])   ans++;
        }
//         map<char, vector<int>> hsh;
//         for(int i = 0; i < s.size(); i++)
//             hsh[s[i]].push_back(i);
        
//         for(int i = 0; i < s.size(); i++){
//             vector<int> temp = hsh[s[i]];
//             auto id = upper_bound(temp.begin(), temp.end(), i);
//             while(id != temp.end()){
//                 string s1 = s.substr(i, *id-i+1);
//                 string s2 = s1;
//                 reverse(s2.begin(), s2.end());
                
//                 if(s1 == s2) ans++;
//                 id++;
//             }
//         }
        
        return ans;
    }
};