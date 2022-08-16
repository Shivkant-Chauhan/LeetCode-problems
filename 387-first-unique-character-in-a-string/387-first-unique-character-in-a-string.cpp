class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hsh;
        for(int i = 0; i < s.size(); i++){
            hsh[s[i]]++;
        }
        
        for(int i = 0; i < s.size(); i++)
            if(hsh[s[i]] == 1)  return i;
        
        return -1;
    }
};