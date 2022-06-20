class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& l, const string& r)
                                            {return l.size()>r.size();});
        
        set<string> helper;
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            auto it = helper.find(words[i]);
            if(it == helper.end()){
                string x = words[i];
                helper.insert(x);
                ans.push_back(x);
                while(x.size() > 0){
                    x = x.substr(1);
                    helper.insert(x);
                }
            }
        }
        
        int ret = ans.size();
        for(auto &i : ans){
            ret += i.size();
        }
        
        return ret;
    }
};