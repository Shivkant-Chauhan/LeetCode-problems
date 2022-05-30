class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int temp = (1LL*dividend)/divisor;
        if(temp > INT_MAX)  return INT_MAX;
        if(temp < INT_MIN)  return INT_MIN;
        
        return temp;
    }
};