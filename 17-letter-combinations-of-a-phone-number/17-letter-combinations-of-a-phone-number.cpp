class Solution {
public:
    int k = 1;
    string comb(int i){
        string ans = "";
        
        if(i == 2)          ans = "abc";
        else if(i == 3)     ans = "def";
        else if(i == 4)     ans = "ghi";
        else if(i == 5)     ans = "jkl";
        else if(i == 6)     ans = "mno";
        else if(i == 7)     ans = "pqrs";
        else if(i == 8)     ans = "tuv";
        else if(i == 9)     ans = "wxyz";

        return ans;
    }
    
    void helper(string digits, vector<string>& pass){
        if(digits.size() == 0)  return ;
        
        string curr = comb(digits[0]-'0');
        k *= curr.size();
        vector<string> temp(256);
        int z = 0;
        for(int i = 0; i < 64; i++){
            for(int k = 0; k < curr.size(); k++){
                temp[z++] = pass[i] + curr[k];
            }
        }
        
        for(int i = 0; i < 256; i++)
            pass[i] = temp[i];
 
        helper(digits.substr(1), pass);
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            vector<string> pass;
            return pass;
        }
        
        vector<string> pass(256, "");
        helper(digits, pass);
        
        vector<string> pass2;
        for(int i = 0; i < k; i++){
            pass2.push_back(pass[i]);
        }
        
        return pass2;
    }
};