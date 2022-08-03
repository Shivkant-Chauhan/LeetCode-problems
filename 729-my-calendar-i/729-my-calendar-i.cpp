class MyCalendar {
public:
    vector<int> st, ed;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0; i < st.size(); i++){
            if(start > st[i] && start < ed[i])  return false;
            if(end > st[i] && end < ed[i])      return false;
            if(start <= st[i] && end >= ed[i])    return false;
        }
        
        st.push_back(start);
        ed.push_back(end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */