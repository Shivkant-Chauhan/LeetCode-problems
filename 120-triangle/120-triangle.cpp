class Solution {
public:
//     int helper(vector<vector<int>>& triangle, int id, int row, int sum, int** dp){
//         if(row == triangle.size()){
//             return sum;
//         }
        
//         if(dp[row][id] != -1)   return dp[row][id];
        
//         int p1 = INT_MAX, p2 = INT_MAX;
//         p1 = helper(triangle, id, row+1, sum+triangle[row][id], dp);
//         if(id+1 < triangle[row].size())
//             p2 = helper(triangle, id+1, row+1, sum+triangle[row][id+1], dp);
        
//         dp[id][row] = min(p1, p2);
//         return dp[row][id];
//     }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
//         int** dp = new int*[n];
//         for(int i = 0; i < n; i++){
//             dp[i] = new int[n];
//             for(int j = 0; j < n; j++)  dp[i][j] = -1;
//         }
//         int sum = triangle[0][0];
//         int x = helper(triangle, 0, 1, sum, dp);
        
//         int mini = INT_MAX;
//         for(int i = 0; i < n; i++){
//             if(dp[n-1][i] != -1)
//                 mini = min(mini, dp[n-1][i]);
//         }
//         return mini;
        
        
        for(int i = n-1; i > 0; i--){
            for(int j = 1; j < triangle[i].size(); j++){
                triangle[i-1][j-1] += min(triangle[i][j], triangle[i][j-1]);
            }
        }
        
        return triangle[0][0];
    }
};