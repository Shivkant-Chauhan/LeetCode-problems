class Solution {
public:
    int subarraySum(vector<int>& pf, int target){
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> hsh;
        hsh[0]++;
        for(int i = 0; i < pf.size(); i++){
            sum += pf[i];
            int diff = sum - target;
            ans += hsh[diff];
            hsh[sum]++;
        }
        
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            vector<int> pf(matrix[0].size(), 0);
            for(int j = i; j < matrix.size(); j++){
                for(int k = 0; k < matrix[0].size(); k++){
                    pf[k] += matrix[j][k];
                }
                ans += subarraySum(pf, target);
            }
        }
        return ans;
    }
};