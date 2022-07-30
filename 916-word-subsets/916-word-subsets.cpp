class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2){
        vector<string> ans;
        vector<vector<int>> hsh;
        for(int i = 0; i < words1.size(); i++){
            vector<int> h(26, 0);
            for(int k = 0; k < words1[i].size(); k++){
                h[words1[i][k]-'a']++;
            }
            hsh.push_back(h);
        }
        
        vector<int> hshSma(26, 0);
        for(int i = 0; i < words2.size(); i++){
            vector<int> h(26, 0);
            for(int k = 0; k < words2[i].size(); k++){
                h[words2[i][k]-'a']++;
            }
            for(int i = 0; i < 26; i++){
                hshSma[i] = max(hshSma[i], h[i]);
            }
        }
        
        for(int i = 0; i < hsh.size(); i++){
            bool flag = 1;
            for(int k = 0; k < 26; k++){
                if(hshSma[k] > hsh[i][k]){
                    flag = 0;
                    break;
                }
            }
            if(flag)    ans.push_back(words1[i]);
        }
        
        return ans;
    }
    
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//         vector<string> ans;
//         for(int i = 0; i < words1.size(); i++){
//             vector<int> hsh(26, 0);
//             for(int k = 0; k < words1[i].size(); k++){
//                 hsh[words1[i][k] - 'a']++;
//             }
//             bool flag = 1;
//             for(int j = 0; j < words2.size(); j++){
//                 string sma = words2[j];
//                 vector<int> smaHsh(26, 0);
//                 for(int k = 0; k < sma.size(); k++){
//                     smaHsh[sma[k]-'a']++;
//                 }
//                 for(int z = 0; z < 26; z++){
//                     if(hsh[z] < smaHsh[z]){
//                         flag = 0;
//                         break;
//                     }
//                 }
//                 if(!flag)   break ;
//             }
//             if(flag){
//                 ans.push_back(words1[i]);
//             }
//         }
        
//         return ans;
//     }
};