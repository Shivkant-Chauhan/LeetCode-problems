class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask;
        for(int i = 0; i < words.size(); i++){
            int maskI = (1<<(words[i][0]-'a'));
            for(int k = 1; k < words[i].size(); k++){
                maskI |= (1<<(words[i][k]-'a'));
                // cout << (1<<(words[i][k]-'a')) << " ";
            }
            mask.push_back(maskI);
        }
        
        int output = 0;
        for(int i = 0; i < mask.size(); i++){
            // cout << mask[i] << " ";
            for(int j = i+1; j < mask.size(); j++){
                int temp = (mask[i] & mask[j]);
                if(temp == 0){
                    int si = words[i].size() * words[j].size();
                    output = max(output, si);
                }
            }
        }
        
        return output;
        
        
        //approach 1
//         vector<vector<int>> hsh;
//         for(int i = 0; i < words.size(); i++){
//             string s = words[i];
//             // int arr[26] = {0};
//             vector<int> arr(26,0);
//             for(int j = 0; j < s.size(); j++){
//                 arr[s[j] - 'a']++;
//             }
//             hsh.push_back(arr);
//         }
        
//         int output = 0;
//         for(int i = 0; i < hsh.size(); i++){
//             for(int j = i+1; j < hsh.size(); j++){
//                 bool flag = true;
//                 for(int k = 0; k < 26; k++){
//                     if(hsh[i][k]!=0 && hsh[j][k]!=0){
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     int temp = words[i].size() * words[j].size();
//                     output = max(output, temp);
//                 }
                
//             }
//         }
        
//         return output;
    }
};