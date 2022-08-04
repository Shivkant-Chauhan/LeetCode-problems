class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q == 0)  return 0;
        if(q == p)  return 1;
        
        if((p&1) == 0)
            if(p/2 == q)    return 2;
        
        if(p%q == 0){
            p /= q;
            if(p&1) return 1;
            else    return 2;
        } else{
            while(p%2 == 0 && q%2 == 0){
                p >>= 1;
                q >>= 1;
            }
            if(p%2==0 && q%2==0){   // even even
                return 2;
            } else if(p%2!=0 && q%2!=0){    // odd odd
                return 1;
            } else if(p%2==0 && q%2!=0){    // even odd
                return 2;
            } else{         // odd even
                return 0;
            }
        }
    }
};