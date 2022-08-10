#include <unordered_map>
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& nums) {
        int n = nums.size();
        int mod = (1e9 + 7);
        sort(nums.begin(), nums.end());
        unordered_map<int, int> checker;
        for(int i = 0; i < n; i++)  checker[nums[i]] = i+1;
        
        vector<long long> dp(n+1, 1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int curr = nums[i-1];
            long long x = 0;
            for(int j = 1; j < i; j++){
                if(curr%nums[j-1] == 0){
                    int temp = curr/nums[j-1];
                    if(checker.find(temp) != checker.end()){
                        dp[i] = (dp[i] + (1LL*dp[j] * dp[checker[temp]])%mod)%mod;
                    }
                }
            }
        }
        
        long long ans = 0;
        for(int i = 0; i <= n; i++) ans = (ans+dp[i]) % mod;
        return ans;
    }
};