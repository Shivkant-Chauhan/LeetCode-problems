class Solution {
public:
    bool backspaceCompare(string s, string t) {
    //trying for O(1) space complexity
        int p1 = 0, p2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '#'){
                s[p1] = s[i];
                p1++;
            } else{
                p1--;
                if(p1 < 0)   p1 = 0;
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '#'){
                t[p2] = t[i];
                p2++;
            } else{
                p2--;
                if(p2 < 0)   p2 = 0;
            }
        }
        
        if(p1 == p2){
            for(int i = 0; i < p1; i++)
                if(s[i] != t[i])
                    return false;
        } else
            return false;
        
        return true;
        
    // accepted solution 
    //this was taking O(n) space complexity
        /*stack<char> helper;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(helper.size() > 0)   helper.pop();
            } else{
                helper.push(s[i]);
            }
        }
        string temp1 = "";
        while(helper.size() > 0){
            temp1 = helper.top() + temp1;
            helper.pop();
        }
        
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(helper.size() > 0)   helper.pop();
            } else{
                helper.push(t[i]);
            }
        }
        string temp2 = "";
        while(helper.size() > 0){
            temp2 = helper.top() + temp2;
            helper.pop();
        }
        
        if(temp1 == temp2)  return true;
        else                return false;*/
    }
};