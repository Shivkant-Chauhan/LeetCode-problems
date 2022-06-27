class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(int i = 0; i < n.size(); i++){
            int k = n[i] - '0';
            ans = max(ans, k);
            if(ans == 9)    return ans;
        }
        return ans;
    }
};