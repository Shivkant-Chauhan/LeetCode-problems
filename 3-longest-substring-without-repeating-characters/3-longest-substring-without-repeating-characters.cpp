class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            map<char, int> hsh;
            int temp = 0;
            for(int j = i; j < s.size(); j++){
                auto it = hsh.find(s[j]);
                if(it != hsh.end()) break;
                temp++;
                hsh[s[j]]++;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};