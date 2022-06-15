class Solution {
public:
    bool comparator(string l, string r){
        return l.size()<r.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& l, const string& r)
                                                {return l.size() < r.size();});
        
        unordered_map<string, int> dp;
        
        int ans = 1;
        for(int i = 0; i < words.size(); i++){
            dp[words[i]] = 1;
            for(int j = 0; j < words[i].size(); j++){
                string p = words[i].substr(0, j) + words[i].substr(j+1);
                if(dp.find(p) != dp.end()){
                    dp[words[i]] = dp[p]+1;
                    ans = max(ans, dp[words[i]]);
                }
            }
        }
        
        return ans;
    }
    
//     bool checker(string prev, string curr){
//         int p1 = 0;
//         int a = 0;
//         while(p1<curr.size() && prev[p1]==curr[p1]){
//             p1++;
//             a++;
//         }
//         p1++;
//         while(p1<curr.size() && prev[p1]==curr[p1-1]){
//             p1++;
//             a++;
//         }
        
//         return (a==curr.size());
//     }
    
//     int helper(vector<string>& words, string curr){
//         int ans = 1;
//         for(int i = 0; i < words.size(); i++){
//             if(words.size()-1 == curr.size()){
//                 bool p = checker(curr, words[i]);
//                 if(!p)  continue;
                
//                 int t = helper(words, words[i]);
//                 ans = max(ans, t+1);
//             }
//         }
        
//         return ans;
//     }
    
//     int longestStrChain(vector<string>& words) {
//         int ans = 1;
//         for(int i = 0; i < words.size(); i++){
//             int p = helper(words, words[i]);
//             ans = max(ans, p+1);
//         }
        
//         return ans;
//     }
};