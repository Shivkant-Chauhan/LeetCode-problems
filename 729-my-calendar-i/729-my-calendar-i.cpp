#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, //put greater in place of less for storing ordered set in desc order
        rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<int, null_type, greater<int>, //put greater in place of less for storing ordered set in desc order
        rb_tree_tag, tree_order_statistics_node_update> pbds2;


class MyCalendar {
public:
    vector<int> st, ed;
    map<int, int> mp;
    
    MyCalendar() {
    }
    
    bool book(int start, int end) {
//         for(int i = 0; i < st.size(); i++){
//             if(start > st[i] && start < ed[i])  return false;
//             if(end > st[i] && end < ed[i])      return false;
//             if(start <= st[i] && end >= ed[i])    return false;
//         }
        
//         st.push_back(start);
//         ed.push_back(end);
//         return true;
        
        
        auto it=mp.upper_bound(start);
        if(it==mp.end() || it->second>=end){
             mp[end]=start;
             return true;
        } else{
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */