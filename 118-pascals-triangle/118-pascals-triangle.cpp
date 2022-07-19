class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> a(1, 1);
        ans.push_back(a);
        for(int i = 1; i < numRows; i++){
            vector<int> x(i+1);
            for(int j = 0; j < i+1; j++){
                if(j==0 || j==i){
                    x[j] = 1;
                    continue;
                }
                x[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(x);
        }
        
        return ans;
    }
};