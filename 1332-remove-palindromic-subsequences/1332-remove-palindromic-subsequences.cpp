class Solution {
public:
    int removePalindromeSub(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        if(t == s)
            return 1;
        else
            return 2;
    }
};