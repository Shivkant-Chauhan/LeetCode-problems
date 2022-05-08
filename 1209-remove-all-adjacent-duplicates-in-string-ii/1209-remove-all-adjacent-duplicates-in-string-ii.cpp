class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<string> helper;
        int p1 = 0;
        while(p1 < n){
            if(helper.size() == 0){
                string temp = "";
                temp += s[p1];
                helper.push(temp);
                p1++;
                continue;
            }
            if((helper.top())[0] == s[p1]){
                helper.top() += s[p1];
            } else{
                string temp = "";
                temp += s[p1];
                helper.push(temp);
            }
            
            string x = helper.top();
            if(x.size() == k)
                helper.pop();
           
            p1++;
        }
        
        string output = "";
        while(helper.size() > 0){
            string temp = helper.top();
            output += temp;
            helper.pop();
        }
        
        reverse(output.begin(), output.end());
        return output;
    }
};