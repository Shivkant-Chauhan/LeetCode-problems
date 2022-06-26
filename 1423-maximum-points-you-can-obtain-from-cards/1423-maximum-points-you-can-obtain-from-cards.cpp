class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += v[i];
        }
        
        int ans = sum;
        int n = v.size();
        for(int i = k-1; i >= 0; i--){
            sum -= v[i];
            int z = n+i-k;
            sum += v[z];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};