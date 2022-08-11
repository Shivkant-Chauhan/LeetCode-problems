class CustomStack {
public:
    stack<int> st;
    int siz;
    CustomStack(int maxSize) {
        siz = maxSize;
    }
    
    void push(int x) {
        if(siz > 0){
            st.push(x);
            siz--;
        }
    }
    
    int pop() {
        if(st.size() > 0){
            int t = st.top();
            st.pop();
            siz++;
            return t;
        } else  return -1;
    }
    
    void increment(int k, int val) {
        stack<int> helper;
        int ctr = st.size()-k;
        while(ctr > 0){
            helper.push(st.top());
            st.pop();
            ctr--;
        }
        while(st.size() > 0){
            helper.push(st.top()+val);
            st.pop();
        }
        while(helper.size() > 0){
            st.push(helper.top());
            helper.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */