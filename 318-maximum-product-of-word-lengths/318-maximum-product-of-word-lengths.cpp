class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> hsh;
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            // int arr[26] = {0};
            vector<int> arr(26,0);
            for(int j = 0; j < s.size(); j++){
                arr[s[j] - 'a']++;
            }
            hsh.push_back(arr);
        }
        
        int output = 0;
        for(int i = 0; i < hsh.size(); i++){
            for(int j = i+1; j < hsh.size(); j++){
                bool flag = true;
                for(int k = 0; k < 26; k++){
                    if(hsh[i][k]!=0 && hsh[j][k]!=0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    int temp = words[i].size() * words[j].size();
                    output = max(output, temp);
                }
                
            }
        }
        
        return output;
    }
};