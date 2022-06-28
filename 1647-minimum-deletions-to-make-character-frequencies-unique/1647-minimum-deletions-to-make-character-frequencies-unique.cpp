class Solution {
public:
    int minDeletions(string s) {
        vector<int> hsh(26, 0);
        for(int i = 0; i < s.size(); i++){
            hsh[s[i]-'a']++;
        }
        
        int ans = 0;
        set<int> freq;
        for(int i = 0; i < 26; i++){
            if(hsh[i] != 0){
                auto it = freq.find(hsh[i]);
                if(it == freq.end()){
                    freq.insert(hsh[i]);
                } else{
                    while(it != freq.end() && hsh[i] > 0){
                        hsh[i]--;
                        ans++;
                        it = freq.find(hsh[i]);
                    }
                    if(hsh[i] > 0)  freq.insert(hsh[i]);
                }
            }
        }
        
        return ans;
    }
};