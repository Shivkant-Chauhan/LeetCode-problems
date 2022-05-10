class Solution {
public:
    vector<vector<int>> output;
    void helper(int k, int n, int num, vector<int> curr){
        if(k==0 && n==0){
            output.push_back(curr);
            return ;
        }
        if(num > 9)             return ;
        if(n <= 0 || k <= 0)    return ;
        
        vector<int> temp = curr;
        temp.push_back(num);
        helper(k-1, n-num, num+1, temp);
        helper(k, n, num+1, curr);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        helper(k, n, 1, curr);
        
        return output;
    }
};