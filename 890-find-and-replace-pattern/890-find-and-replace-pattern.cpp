class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            string curr = words[i];
            if(pattern.size() != curr.size())   continue ;
            map<char, char> helper, rev;
            bool flag = 1;
            for(int i = 0; i < curr.size(); i++){
                auto it = helper.find(pattern[i]), it2 = rev.find(curr[i]);
                if(it == helper.end() && it2 == rev.end()){
                    helper[pattern[i]] = curr[i];
                    rev[curr[i]] = pattern[i];
                } else{
                    if(helper[pattern[i]] != curr[i]){
                        flag = 0;
                        break;
                    }
                    if(rev[curr[i]] != pattern[i]){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag)    ans.push_back(curr);
        }
        
        return ans;
    }
};