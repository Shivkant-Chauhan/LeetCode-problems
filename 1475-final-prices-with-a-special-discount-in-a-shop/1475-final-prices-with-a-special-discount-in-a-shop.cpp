class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n);
        ans[n-1] = prices[n-1];
        stack<int> st;
        st.push(prices[n-1]);
        
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && prices[i]<st.top())    st.pop();
            if(st.empty()){
                ans[i] = prices[i];
            } else{
                ans[i] = prices[i] - st.top();
            }
            st.push(prices[i]);
        }
        
        return ans;
    }
};