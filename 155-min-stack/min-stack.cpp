class MinStack {
public:

    stack<long long>st;long long mi;
    MinStack() {
        mi = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mi = val;
            st.push(val);
        }
        else{
            if(val  >= mi){
                st.push(val);
            }
            else{
                st.push(2LL*val - mi);
                mi = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        long long x = st.top();
        st.pop();
        if(x < mi){
            mi = 2LL*mi  - x;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long s = st.top();
        if(s < mi){
            return mi;
        }
        return s;
    }
    
    int getMin() {
        return mi;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */