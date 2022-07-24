class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] > target)   continue;
            if(matrix[i][matrix[i].size()-1] < target)  continue;
            
            int lo = 0, hi = matrix[i].size();
            while(hi-lo > 0){
                int m = (hi+lo) /2;
                int x = matrix[i][m];
                if(x == target)     return 1;
                else if(x > target) hi = m;
                else                lo = m+1;
            }
        }
        
        return 0;
        
        
        // for(int i = 0; i < matrix.size(); i++){
        //     if(matrix[i][matrix[i].size()-1] < target)  continue;
        //     if(matrix[i][0] > target)   continue;
        //     for(int j = 0; j < matrix[i].size(); j++){
        //         if(matrix[i][j] == target)  return 1;
        //         else if(matrix[i][j] > target)  continue;
        //     }
        // }
        return 0;
    }
};