class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            int diff = abs(st.top() - s[i]);
            if(diff == 32)  st.pop();
            else            st.push(s[i]);
        }
        
        string output = "";
        while(st.size() > 0){
            output += st.top();
            st.pop();
        }
        
        reverse(output.begin(), output.end());
        return output;
    }
};