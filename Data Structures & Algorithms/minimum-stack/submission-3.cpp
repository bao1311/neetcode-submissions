class MinStack {
public:

    stack<int> st;
    stack<int> minSt;
    MinStack() {
    }
    
    void push(int val) {
        int mn = min(val, minSt.empty() ?  val : minSt.top());
        st.push(val);
        minSt.push(mn);
        cout << mn << ' ';
    }
    
    void pop() {
       st.pop();
       minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top(); 
    }
};
