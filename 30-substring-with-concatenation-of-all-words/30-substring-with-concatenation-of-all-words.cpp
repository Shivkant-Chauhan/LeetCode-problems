class Solution {
public:
    
//     bool isEqual(map<string, int> hsh, map<string, int> checker){
//         // for(auto &i : hsh){
//         //     cout << i.first << i.second << " ";
//         // }
//         // cout << endl;
//         auto it1 = hsh.begin(), it2 = checker.begin();
//         while(it1 != hsh.end()){
//             if(it1->first != it2->first || it1->second != it2->second)  return 0;
            
//             it1++;
//             it2++;
//         }
        
//         return 1;
//     }
    map<string, int> hsh;
    
    bool helper(string checker, int l){
        map<string, int> temp;
        for(int i = 0; i < checker.size(); i+=l){
            string t = checker.substr(i, l);
            temp[t]++;
        }
        
        return (hsh==temp);
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        int l = words[0].size();
        int full = n*l;
        
        for(int i = 0; i < n; i++){
            hsh[words[i]]++;
        }

        for(int i = 0; i+full-1 < s.size(); i++){
            string checker = s.substr(i, full);
            if(helper(checker, l))    ans.push_back(i);
        }
        
        return ans;
//         int n = words.size();
//         int l = words[0].size();
//         map<string, int> hsh;
//         for(int i = 0; i < n; i++){
//             hsh[words[i]]++;
//         }

//         vector<int> ans;
//         map<string, int> checker;
//         for(int i = 0; i < l*n; i+=l){
//             string temp = s.substr(i, l);
//             checker[temp]++;
//         }
//         if(isEqual(hsh, checker))   ans.push_back(0);
        
//         for(int i = l*n; i < s.size(); i+=l){
//             string t1 = s.substr(i, l);
//             string t2 = s.substr(i-(l*n), l);
//             checker[t1]++;
//             checker[t2]--;
            
//             if(isEqual(hsh, checker)){
//                 ans.push_back(i-((n-1)*l));
//             }
//         }
        // return ans;
    }
};