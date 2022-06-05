class Solution {
public:
    bool checkPos(vector<string>& board, int i, int j, int n){
        for(int k = 0; k < j; k++){
            if(board[i][k] == 'q')  return false;
        }
        for(int k = 0; k < i; k++){
            if(board[k][j] == 'q')  return false;
        }
        
        int p1 = i-1, p2 = j-1;
        while(p1>=0 && p2>=0){
            if(board[p1][p2] == 'q')    return false;
            
            p1--;
            p2--;
        }
        
        p1 = i-1;
        p2 = j+1;
        while(p1>=0 && p2<n){
            if(board[p1][p2] == 'q')    return false;
            
            p1--;
            p2++;
        }
        
        return true;
    }
    
    int helper(vector<string>& board, int n, int row){
        if(n == row)    return 1;
        
        int pass = 0;
        for(int i = 0; i < n; i++){
            if(checkPos(board, row, i, n)){
                board[row][i] = 'q';
                pass +=  helper(board, n, row+1);
                board[row][i] = '.';
            }
        }
        
        return pass;
    }
    
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        
        return helper(board, n, 0);
        
    }
};