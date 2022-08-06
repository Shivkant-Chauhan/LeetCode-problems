class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string output = "";
        if(!n)  return output;
        
        
        //easier approach
        int i = 0, j = 0;
        int l = 0, r = 0;
        while(i < n){
            while(true){
                if(s[j] == '(') l++;
                else            r++;
                if(l == r)  break;
                j++;
            }

            output += s.substr(i+1, j-i-1);
            i = j+1;
            j++;
        }
        
        
            
        
        // stack<char> st;
        // st.push(s[0]);
        // for(int i = 1; i < n; i++){
        //     if(s[i] == '('){
        //         if(st.size() > 0)
        //             output += s[i];
        //         st.push(s[i]);
        //     } else{
        //         st.pop();
        //         if(!st.empty()) output += s[i];
        //     }
        // }
        
        return output;
    }
};