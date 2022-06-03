// class NumMatrix {
//     vector<vector<int>> matrix;
// public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         this->matrix = matrix;
//         for(int i = 1; i < matrix[0].size(); i++){
//             matrix[0][i] += matrix[0][i-1];
//         }
//         for(int i = 1; i < matrix.size(); i++){
//             matrix[i][0] += matrix[i-1][0];
//         }
        
//         for(int i = 1; i < matrix.size(); i++){
//             for(int j = 1; j < matrix[i].size(); j++){
//                 matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
//             }
//         }
        
//         // for(int i = 0; i < matrix.size(); i++){
//         //     for(int j = 0; j < matrix[i].size(); j++){
//         //         cout << matrix[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         int sum = matrix[row2][col2];
        
//         if(row1 == 0 && col1 == 0){
//             return sum;
//         } else if(row1 == 0){
//             sum -= matrix[row2][col1-1];
//             return sum;
//         } else if(col1 == 0){
//             sum -= matrix[row1-1][col2];
//             return sum;
//         } else{
//             sum -= matrix[row1-1][col2];
//             sum -= matrix[row2][col1-1];
//             sum += matrix[row1-1][col1-1];
            
//             return sum;
//         }
//     }
// };


//accpeted but i want some better space complexity !

class NumMatrix {
    vector<vector<int>> matrix;
    // vector<vector<int>> pf;
public:
//     void prefix_sum(){
//         int r = (this->matrix).size();
//         int c = (this->matrix)[0].size();
//         for(int i = 1; i <= r; i++){
//             for(int j = 1; j <= c; j++){
//                 pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + matrix[i-1][j-1];
//             }
//         }
        
//         // for(int i = 0; i <= r; i++){
//         //     for(int j = 0; j <= c; j++){
//         //         cout << pf[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//     }
    
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        vector<vector<int>> temp;
        vector<int> t(matrix[0].size()+1, 0);
        for(int i = 0; i <= matrix.size()+1; i++){
            vector<int> t(matrix[0].size()+1, 0);
            temp.push_back(t);
        }
        int r = (this->matrix).size();
        int c = (this->matrix)[0].size();
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                temp[i][j] = temp[i-1][j] + temp[i][j-1] - temp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        this->matrix = temp;
        // this->pf = temp;
        // prefix_sum();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = matrix[row2+1][col2+1];
        sum -= matrix[row1][col2+1];
        sum -= matrix[row2+1][col1];
        sum += matrix[row1][col1];
        // int sum = 0;
        // for(int i = row1; i <= row2; i++){
        //     for(int j = col1; j <= col2; j++){
        //         sum += (this->matrix)[i][j];
        //     }
        // }
        return sum;
    }
};
