class Solution {
public:
    bool isAnagram(string s, string t) {
        int hsh_s[27], hsh_t[27];
        fill(hsh_s,hsh_s+27,0);
        fill(hsh_t,hsh_t+27,0);
        for(int i = 0; i < s.size(); i++){
            hsh_s[s[i]-96]++;
            // cout<<hsh_s[s[i]-96]<<" ";
        }
        for(int i = 0; i < t.size(); i++){
            hsh_t[t[i]-96]++;
            // cout<<hsh_t[t[i]-96]<<" ";
        }
        
        for(int i = 1; i < 27; i++){
            // cout<<hsh_s[i]<<hsh_t[i]<<endl;
            
            if(hsh_s[i] != hsh_t[i])
                return false;
        }
        
        return true;
    }
};