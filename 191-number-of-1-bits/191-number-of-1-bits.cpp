class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = __builtin_popcountll(n);
        return x;
    }
};