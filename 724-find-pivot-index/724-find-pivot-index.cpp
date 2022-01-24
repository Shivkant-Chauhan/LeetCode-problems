class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int len = arr.size();
        int pf1[len+1];
        int pf2[len+1];
        fill(pf1,pf1+len+1,0);
        fill(pf2,pf2+len+1,0);
        for(int i = 0; i < len; i++){
            if(i == 0)
                pf1[i] = arr[i];
            else
                pf1[i] = arr[i] + pf1[i-1];
        }
        for(int i = len-1; i >=0; i--){
            if(i == len-1)
                pf2[i] = arr[i];
            else
                pf2[i] = arr[i] + pf2[i+1];
        }
        for(int i = 0; i < len; i++){
            int l = 0, r = 0;
            if(i == 0)
                l = 0;
            else
                l = pf1[i-1];
            
            if(i == len-1)
                r = 0;
            else
                r = pf2[i+1];
            
            if(l == r)
                return i;
        }
    return -1;
    }
};