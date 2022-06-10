class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ans = 0, prev = 0;
        for(int i=0;i<s.size();i++) {
            ans = max(ans, i-prev);
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=prev) {
                prev = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
        }
		
        if(ans < s.size() - prev)
            return s.size() - prev;
        
        return ans;
    }
};