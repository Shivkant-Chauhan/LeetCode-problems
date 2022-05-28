class Solution {
public:
    void dfs(vector<vector<char>>& grid, int** visited, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        
        visited[i][j] = 1;
        
//         for(int i = 0; i < n; i++){
//             if(i == I)  continue;
//             for(int j = 0; j < m; j++){
//                 if(j == J)  continue;
                
                
                if(i > 0){
                    if(visited[i-1][j]==0 && grid[i-1][j]=='1')
                        dfs(grid, visited, i-1, j);
                }
                if(j > 0){
                    if(visited[i][j-1]==0 && grid[i][j-1]=='1')
                        dfs(grid, visited, i, j-1);
                }
                if(i < n-1){
                    if(visited[i+1][j]==0 && grid[i+1][j]=='1')
                        dfs(grid, visited, i+1, j);
                }
                if(j < m-1){
                    if(visited[i][j+1]==0 && grid[i][j+1]=='1')
                        dfs(grid, visited, i, j+1);
                }
                
        //     }
        // }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int** visited = new int*[grid.size()];
        for(int i = 0; i < n; i++){
            visited[i] = new int[m];
            for(int j = 0; j < m; j++){
                visited[i][j] = 0;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return cnt;
    }
};