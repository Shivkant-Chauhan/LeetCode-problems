class Solution {
public:
  string longestPalindrome(string s) {
      if(s.size() < 2)  return s;
      
      int start = -1, len = -1;
      for(int i = 0; i < s.size(); i++){
          // odd palindrome
          int k1 = i, k2 = i;
          while(k1>0 && k2<s.size()-1 && s[k1-1]==s[k2+1]){
              k1--; k2++;
          }
          
          if(len < k2-k1+1){
              len = k2-k1+1;
              start = k1;
          }
          
          
          // even palindrome
          k1 = i; k2 = i+1;
          if(s[k1]==s[k2]){
              while(k1>0 && k2<s.size()-1 && s[k1-1]==s[k2+1]){
                  k1--; k2++;
              }
              if(len < k2-k1+1){
                  len = k2-k1+1;
                  start = k1;
              }   
          }
          
      }
      // cout << start << " " << len;
      return s.substr(start, len);
      
      
      
      
      
      
      
      
      
      
      
        // if (s.empty()) return "";
        // if (s.size() == 1) return s;
        // int min_start = 0, max_len = 1;
        // for (int i = 0; i < s.size();) {
        //     if (s.size() - i <= max_len / 2) break;
        //     int j = i, k = i;
        //     while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
        //     i = k+1;
        //     while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
        //     int new_len = k - j + 1;
        //     if (new_len > max_len) { min_start = j; max_len = new_len; }
        // }
        // return s.substr(min_start, max_len);
      }
  
  };