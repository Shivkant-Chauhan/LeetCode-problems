// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include <bits/stdc++.h>
class Solution{
    public:
        int countWords(string list[], int n){
           int ans = 0;
           map<string,int> m;
           for(int i = 0; i < n; i++){
               m[list[i]]++;
           }
        //   for(auto &it : m){
        //       if(it->second == 2)
        //             ans++;
        //   }
        for(map<string,int>::iterator it = m.begin(); it!=m.end();it++){
            if(it->second == 2)
                ans++;
        }
           
           return ans;
        }

};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string list[n];
        for(int i=0;i<n;i++)
            cin>>list[i];
        Solution ob;    
        cout <<ob.countWords(list, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends