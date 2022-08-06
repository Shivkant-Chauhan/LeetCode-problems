class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string output = "";
        if(!n)  return output;
        
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < n; i++){
            if(s[i] == '('){
                if(st.size() > 0)
                    output += s[i];
                st.push(s[i]);
            } else{
                st.pop();
                if(!st.empty()) output += s[i];
            }
        }
        
        return output;
    }
};