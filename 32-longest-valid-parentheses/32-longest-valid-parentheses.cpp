class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)   return 0;
        
        //approach 2
        
        int output = 0;
        
        for(int j = 0; j < s.size(); j++){
            int l = 0, r = 0;
            for(int i = j; i < s.size(); i++){
                if(s[i] == ')') r++;
                else            l++;

                if(r > l){
                    l = 0;
                    r = 0;
                } else if(l == r){
                    output = max(output, l*2);
                }
                // cout <<l<<r<<" ";
            }
        }
        
        
        
        
//         stack<int> st;
//         st.push(-1);
//         int output = 0;
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == ')'){
//                 if(st.size() > 0){
//                     st.pop();
//                     if(st.size() == 0)  st.push(i);
                    
//                     output = max(output, i-st.top());
                    
//                 } else{
//                     st.push(i);
//                 }
//             } else{
//                 st.push(i);
//             }
//         }
        
        return output;
    }
};