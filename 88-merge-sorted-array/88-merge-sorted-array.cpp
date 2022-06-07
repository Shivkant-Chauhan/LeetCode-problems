class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //O(1) space complexity -->
        int k = m+n-1;
        int p1 = m-1, p2 = n-1;
        while(p1>=0 && p2>=0){
            if(nums1[p1]>nums2[p2]){
                nums1[k--] = nums1[p1--];
            } else{
                nums1[k--] = nums2[p2--];
            }
        }
        while(p1 >= 0){
            nums1[k--] = nums1[p1--];
        }
        while(p2 >= 0){
            nums1[k--] = nums2[p2--];
        }
        
        
        
//         int k1 = 0, k2 = 0;
//         vector<int> ans;
//         while(k1 < m && k2 < n){
//             if(nums1[k1] < nums2[k2]){
//                 ans.push_back(nums1[k1]);
//                 k1++;
//             } else{
//                 ans.push_back(nums2[k2]);
//                 k2++;
//             }
//         }
//         while(k1 < m){
//             ans.push_back(nums1[k1]);
//             k1++;
//         }
//         while(k2 < n){
//             ans.push_back(nums2[k2]);
//             k2++;
//         }
        
//         nums1 = ans;
    }
};