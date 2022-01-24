class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> m;
        map<string,char> m2;
        int slen = s.size();
        int r = 0;
        int k = 0;
        int spaces = 1;
        while(r < slen && k < pattern.size()){
            string part = "";
            while(s[r] != ' ' && r < slen){
                part += s[r];
                r++;
                
            }
            if(s[r] == ' ')
                spaces++;
                
            if(s[r]!='\0')
                r++;
            
            auto it = m.find(pattern[k]);
            if(it != m.end()){
                if(part != it->second)
                    return false;
            }
            else{
                m[pattern[k]] = part;
            }
            
            auto it2 = m2.find(part);
            if(it2 != m2.end()){
                if(pattern[k] != it2->second)
                    return false;
            }
            else{
                m2[part] = pattern[k];
            }
            
            k++;
        }
        cout<<spaces<<" "<<pattern.size();
        if(pattern.size() != spaces)
            return false;
        
        return true;
    }
};


// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//         map<char,string> m;
//         map<string,char> m2;
//         int slen = s.size();
//         int r = 0;
//         int k = 0;
//         int part_ct = 0;
//         while(r < slen && k < pattern.size()){
//             string part = "";
            
//             while(s[r] != ' ' || s[r] != '\0'){
//                 part += s[r];
//                 part_ct++;
//                 r++;
//             }
            
//             if(s[r]!='\0')
//                 r++;
            
//             auto it = m.find(pattern[k]);
//             if(it != m.end()){
//                 if(part != it->second)
//                     return false;
//             }
//             else{
//                 m[pattern[k]] = part;
//             }
            
//             auto it2 = m2.find(part);
//             if(it2 != m2.end()){
//                 if(pattern[k] != it2->second)
//                     return false;
//             }
//             else{
//                 m2[part] = pattern[k];
//             }
            
//             k++;
//         }
//         if(part_ct+1 != pattern.size())
//             return false;
//         //if applying part_ct then abba:dog cat cat dog false ho rha h!
        
//         return true;
//     }
// };