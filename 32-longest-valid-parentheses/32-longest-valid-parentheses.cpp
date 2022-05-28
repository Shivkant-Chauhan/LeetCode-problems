class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)   return 0;
        
        stack<int> st;
        st.push(-1);
        int output = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(st.size() > 0){
                    st.pop();
                    if(st.size() == 0)  st.push(i);
                    
                    output = max(output, i-st.top());
                    
                } else{
                    st.push(i);
                }
            } else{
                st.push(i);
            }
        }
        
        return output;
    }
};