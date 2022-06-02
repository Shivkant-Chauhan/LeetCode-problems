class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix2;
        for(int i = 0; i < matrix[0].size(); i++){
            vector<int> t;
            for(int j = 0; j < matrix.size(); j++){
                t.push_back(matrix[j][i]);
            }
            matrix2.push_back(t);
        }
        
        
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = i+1; j < matrix[i].size(); j++){
        //         int t = matrix[i][j];
        //         matrix[i][j] = matrix[j][i];
        //         matrix[j][i] = t;
        //     }
        // }
        
        return matrix2;
    }
};