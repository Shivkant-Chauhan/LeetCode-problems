class Solution {
public:
//     set<string> allK;
    
//     void helper(string all, int id, int k){
//         if(id >= k)     return ;
//         allK.insert(all);
//         helper(all, id+1, k);
//         all[id] = '1';
//         allK.insert(all);
//         helper(all, id+1, k);
//     }
    
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k)   return false;
        
//         string all(k, '0');
//         helper(all, 0, k);
        
        unordered_set<string> checker;
        string temp = "";
        for(int i = 0; i < k; i++){
            temp += s[i];
        }
        checker.insert(temp);
        for(int i = k; i < s.size(); i++){
            temp = temp.substr(1);
            temp += s[i];
            
            checker.insert(temp);
        }
        
        // if(checker.size() == allK.size())
        if(checker.size() == (1<<k))
            return true;
        else
            return false;
    }
};