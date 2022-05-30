class Solution {
public:
    int divide(long long int dvd, long long int dsr) {
        // long long int temp = (1LL*dvd)/dsr;
        // if(temp > INT_MAX)  return INT_MAX;
        // if(temp < INT_MIN)  return INT_MIN;
        
        if(dvd > INT_MAX) return INT_MAX;
        if(dvd < INT_MIN) return INT_MIN;
        
//         return temp;
        bool flag1 = false, flag2 = false;
        if(dvd < 0){
            dvd = dvd*(-1);
            flag1 = true;
        }
        if(dsr < 0){
            dsr = dsr*(-1);
            flag2 = true;
        }
        
        long long int cnt = 0;
        while(dvd-dsr>=0){
            long long int temp = 1;
            long long int d1 = dvd, d2 = dsr;
            while(d1-d2>=0){
                cnt += temp;
                d1 -= d2;
                d2 *= 2;
                temp *= 2;
            }
            dvd = d1;

            
        }

        if(flag1 && flag2){
            if(cnt > INT_MAX)   return INT_MAX;
            if(cnt < INT_MIN)   return INT_MIN;
            
            return cnt;
        } else if(flag1 || flag2){
            cnt *= (-1);
            if(cnt > INT_MAX)   return INT_MAX;
            if(cnt < INT_MIN)   return INT_MIN;
            
            return cnt;
        } else{
            if(cnt > INT_MAX)   return INT_MAX;
            if(cnt < INT_MIN)   return INT_MIN;
            
            return cnt;
        }
    }
};