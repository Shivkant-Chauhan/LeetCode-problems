#include <climits>
class Solution {
public:
//     int helper(vector<int>& nums, int x, int p1, int p2){
//         if(x == 0){
//             return 0;
//         }
//         if(x < 0){
//             return -1;
//         }
//         if(p1>p2)  return -1;
        
//         int pass1 = -1, pass2 = -1;
//         if(x-nums[p1]>=0){
//             pass1 = helper(nums, x-nums[p1], p1+1, p2);
//             if(pass1 != -1) pass1++;
//         }
//         if(x-nums[p2]>=0){
//             pass2 = helper(nums, x-nums[p2], p1, p2-1);
//             if(pass2 != -1) pass2++;
//         }
        
//         if(pass1!=-1 && pass2!=-1)
//             return min(pass1, pass2);
//         else if(pass1!=-1)  return pass1;
//         else if(pass2!=-1)  return pass2;
//         else    return -1;
//     }
    
    int minOperations(vector<int>& nums, int x) {
        vector<int> pf = nums;
        map<int, int> pf1, pf2;
        pf1[nums[0]] = 1;
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pf[i] += pf[i-1];
            pf1[pf[i]] = i+1;
            sum += nums[i];
        }
        if(sum < x)
            return -1;
        
        reverse(nums.begin(), nums.end());
        pf2[nums[0]] = 1;
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i-1];
            pf2[nums[i]] = i+1;
        }
        
        // for(auto &i : pf1)  cout << i.first << " " << i.second << ". ";
        // cout << endl;
        // for(auto &i : pf2)  cout << i.first << " " << i.second << ". ";
        // cout << endl;
        
        int ans = INT_MAX;
        for(auto &it : pf1){
            if(it.second < 1)   continue;
            int v1 = it.first;
            if(v1 == x){
                ans = min(ans, it.second);
                break;
            }
            if(v1 > x)  break;
            
            int v2 = x - v1;
            int zz = pf2[v2];
            if(zz != 0)
                ans = min(ans, it.second+zz);
            // auto it2 = pf2.find(v2);
            // if(it2 != pf2.end()){
            //     ans = min(ans, it.second+it2->second);
            // }
        }

        for(auto &it : pf2){
            if(it.second < 1)   continue;
            int v1 = it.first;
            if(v1 == x){
                ans = min(ans, it.second);
                break;
            }
            if(v1 > x)  break;
            
            int v2 = x - v1;
            int zz = pf1[v2];
            if(zz != 0)
                ans = min(ans, it.second+zz);
            // auto it2 = pf1.find(v2);
            // if(it2 != pf1.end()){
            //     ans = min(ans, it.second+it2->second);
            // }
            
        }
        
        
        if(ans == INT_MAX)  return -1;
        else                return ans;
        
        
        
        
        
        
        
        
        // int ans = helper(nums, x, 0, nums.size()-1);
        // if(ans == INT_MAX)  return -1;
        // return ans;
    }
};