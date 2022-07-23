#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        pbds ordered_set;
        
        for(int i = n-1; i >= 0; i--){
            ans[i] = ordered_set.order_of_key(nums[i]);
            ordered_set.insert(nums[i]);
        }
        
        return ans;
    }
};


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         // vector<int> ans(n, 0);
//         pbds ordered_set;
        
//         for(int i = n-1; i >= 0; i--){
//             int x = ordered_set.order_of_key({nums[i], -1});
//             ordered_set.insert({nums[i], i});
//             nums[i] = x;
//         }
        
//         return nums;
//     }
// };