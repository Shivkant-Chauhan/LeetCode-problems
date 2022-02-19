// (a^b) % M = (a ^ (b%ETF(M)) ) % M


class Solution {
public:
    int helper(vector<int>& b){
        int ans = 0;
        long long counter = 1;
        for(long long i = b.size()-1; i >= 0; i--){
            ans += (counter*b[i]) % 1140;
            counter = (counter*10) % 1140;
        }
        
        return ans;
    }
    
    int binExp(int a, long long b, int M){
        int ans = 1;
        while(b > 0){
            if(b&1)
                ans = (ans*1LL*a) % M;
            
            a = (a*1LL*a) % M;
            b = b >> 1;
        }
        
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        long long bmod = helper(b);
        int M = 1337;
        a = a % M;
        int output = binExp(a, bmod, M);
        
        return output;
    }
};