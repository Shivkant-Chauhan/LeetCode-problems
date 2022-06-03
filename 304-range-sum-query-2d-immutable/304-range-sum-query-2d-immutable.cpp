class NumMatrix {
    vector<vector<int>> matrix;
    vector<vector<int>> pf;
public:
    void prefix_sum(){
        int r = (this->matrix).size();
        int c = (this->matrix)[0].size();
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        // for(int i = 0; i <= r; i++){
        //     for(int j = 0; j <= c; j++){
        //         cout << pf[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        vector<vector<int>> temp;
        // vector<int> t(marix[0].size()+1, 0);
        for(int i = 0; i <= matrix.size()+1; i++){
            vector<int> t(matrix[0].size()+1, 0);
            temp.push_back(t);
        }
        this->pf = temp;
        prefix_sum();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = pf[row2+1][col2+1];
        sum -= pf[row1][col2+1];
        sum -= pf[row2+1][col1];
        sum += pf[row1][col1];
        // int sum = 0;
        // for(int i = row1; i <= row2; i++){
        //     for(int j = col1; j <= col2; j++){
        //         sum += (this->matrix)[i][j];
        //     }
        // }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */