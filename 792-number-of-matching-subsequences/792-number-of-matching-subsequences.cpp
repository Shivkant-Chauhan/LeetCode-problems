class Solution {
public:
    bool isGood(string& s, string& w){
        int j = 0;
        int n = w.size();
        for(int i = 0; i < s.size(); i++){
            if(j == n)  return true;
            if(s[i] == w[j])    j++;
        }
        
        return (j==n);
    }
    
    int numMatchingSubseq(string& s, vector<string>& words) {
        unordered_map<string, bool> checked;
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            string curr = words[i];
            auto it = checked.find(curr);
            if(it != checked.end()){
                if(it->second)  ans++;
            } else{
                bool h = isGood(s, curr);
                checked[curr] = h;
                if(h)   ans++;
            }
        }
        
        return ans;
    }
};