class MinStack {
private:
            using pii = pair<int, int>; // val, minimum of the below elements till now
        stack<pii> st;
public:
    MinStack() {

    }
    
    void push(int val) {
        int mini = val;

        if(!st.empty()) {
            mini = min(mini, st.top().second);
        }
        st.push({val, mini});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
