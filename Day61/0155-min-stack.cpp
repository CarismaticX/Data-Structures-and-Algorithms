class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                st.push(2LL * val - mini); // store modified value
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long t = st.top();
        st.pop();
        if(t < mini){
            mini = 2LL * mini - t; // retrieve previous minimum
        }
    }
    
    int top() {
        long long t = st.top();
        if(t < mini) return (int)mini;
        return (int)t;
    }
    
    int getMin() {
        return (int)mini;
    }
};
