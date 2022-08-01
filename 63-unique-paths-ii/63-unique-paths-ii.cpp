class Solution {
public:
    int dp[110][110];
    int helper(int r, int c, int m, int n, vector<vector<int>>& grid){
        if(r==m-1 && c==n-1)    return 1;
        if(r >= m || c >= n)    return 0;
        if(grid[r][c] == 1)       return 0;
        
        if(dp[r][c] != -1)  return dp[r][c];
        
        int p1 = helper(r+1, c, m, n, grid);
        int p2 = helper(r, c+1, m, n, grid);
        return dp[r][c] = (p1+p2);

    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof dp);
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return helper(0, 0, m, n, obstacleGrid);
    }
};