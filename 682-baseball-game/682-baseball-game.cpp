class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "C"){
                st.pop();
            } else if(ops[i] == "D"){
                int t = st.top();
                st.push(t*2);
            } else if(ops[i] == "+"){
                int t = st.top();
                st.pop();
                int t2 = st.top();
                st.push(t);
                st.push(t+t2);
            } else{
                int x = stoi(ops[i]);
                st.push(x);
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};