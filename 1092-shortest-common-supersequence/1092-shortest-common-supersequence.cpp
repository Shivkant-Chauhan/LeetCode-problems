class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        // shivkant
        // chauhan
        // lcs:    han
        // my:     schivkauhant
        
        // 1) find lcs
        // 2) simple operation after that
        
        int n = str1.size(), m = str2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // cout << dp[n][m];
        
        string lcs = "";
        int p1 = n, p2 = m;
        while(p1>0 && p2>0){
            if(str1[p1-1] == str2[p2-1]){
                lcs += str1[p1-1];
                p1--;
                p2--;
            } else{
                if(dp[p1-1][p2] > dp[p1][p2-1]){
                    p1--;
                } else{
                    p2--;
                }
            }
        }
        reverse(lcs.begin(), lcs.end());
        // cout << lcs;
        
        
        
        
        
        string output = "";
        p1 = 0;
        p2 = 0;
        int k = 0;
        
        while(k < lcs.size() && p1 < n && p2 < m){
            while(p1<n && lcs[k]!=str1[p1]){
                output += str1[p1++];
            }
            while(p2<m && lcs[k]!=str2[p2]){
                output += str2[p2++];
            }
            output += lcs[k++];
            p1++;
            p2++;
        }
        while(p1 < n){
            output += str1[p1++];
        }
        while(p2 < m){
            output += str2[p2++];
        }
        
        return output;
    }
};