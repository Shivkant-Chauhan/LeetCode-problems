class Solution {
public:
    int numberOfSteps(int num) {
        int ops = 0;
        while(true){
            if(num == 0)    return ops;
            if(num&1){
                ops++;
                num--;
            }
            
            if(num == 0)    return ops;
            num /= 2;
            ops++;
        }
    }
};