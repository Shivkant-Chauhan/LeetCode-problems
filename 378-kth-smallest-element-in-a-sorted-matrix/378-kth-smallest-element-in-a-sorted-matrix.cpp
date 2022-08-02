class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if(k){
                //     pq.push(matrix[i][j]);
                //     k--;
                // } else{
                //     if(pq.top() > matrix[i][j]){
                //         pq.pop();
                //         pq.push(matrix[i][j]);
                //     }
                // }
                pq.push(matrix[i][j]);
                if(pq.size() > k)   pq.pop();
            }
        }
        return pq.top();
    }
};