class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPossible(vector<string>& queen, int i, int j){
        int n = queen.size();
        for(int k = 0; k < n; k++){
            if(k!=j && queen[i][k]=='Q')    return false;
        }
        for(int k = 0; k < n; k++){
            if(k!=i && queen[k][j]=='Q')    return false;
        }
        
        int p1 = i-1, p2 = j-1;
        while(p1>=0 && p2>=0){
            if(queen[p1][p2] == 'Q')    return false;
            p1--;
            p2--;
        }
        p1 = i-1;
        p2 = j+1;
        while(p1>=0 && p2<n){
            if(queen[p1][p2] == 'Q')    return false;
            p1--;
            p2++;
        }
        
        return true;
    }
    
    void helper(vector<string>& queen, int r){
        int n = queen.size();
        if(r >= n){
            ans.push_back(queen);
            return ;
        }
        
        for(int i = 0; i < n; i++){
            if(isPossible(queen, r, i)){
                queen[r][i] = 'Q';
                helper(queen, r+1);
                queen[r][i] = '.';
            }
        }
        
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<string> queen(n, s);
        
        helper(queen, 0);
        
        return ans;
    }
};