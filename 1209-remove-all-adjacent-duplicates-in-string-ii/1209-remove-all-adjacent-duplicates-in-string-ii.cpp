class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<string> st;
        for(int i = 0; i < n; i++){
            if(st.size() == 0){
                string t = "";
                t += s[i];
                st.push(t);
                continue;
            }
            
            if(st.top()[0] == s[i]){
                string t = st.top();
                t += s[i];
                st.pop();
                if(t.size() < k)    st.push(t);
            } else{
                string t = "";
                t += s[i];
                st.push(t);
            }
        }
        
        string ans = "";
        while(st.size() > 0){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};