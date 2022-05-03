class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // int p1 = 0, p2 = 0;
        // int n1 = s.size(), n2 = t.size();
//         while(p1 < n1-1 && p2 < n2-1){
//             while(p1<n1-1 && (p1+1)=='#'){
//                 p1 += 2;
//             }
//             while(p2<n2-1 && (p2+1)=='#'){
//                 p2 += 2;
//             }
            
//             if(s[p1] != s[p2]){
//                 return false;
//             }
//             p1++;
//             p2++;
//         }
//         return true;
    
        stack<char> helper;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(helper.size() > 0)   helper.pop();
            } else{
                helper.push(s[i]);
            }
        }
        string temp1 = "";
        while(helper.size() > 0){
            temp1 = helper.top() + temp1;
            helper.pop();
        }
        
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(helper.size() > 0)   helper.pop();
            } else{
                helper.push(t[i]);
            }
        }
        string temp2 = "";
        while(helper.size() > 0){
            temp2 = helper.top() + temp2;
            helper.pop();
        }
        
        if(temp1 == temp2)  return true;
        else                return false;
    }
};