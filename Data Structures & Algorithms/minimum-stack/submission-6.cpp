class MinStack {
public:

    stack<long> st;
    long min;
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty())
        {
            st.push(0);
            min = val; 
        }
        else
        {
            if (val - min >= 0)
            {
                st.push(val-min);
            }
            else
            {
                st.push(val-min);
                min = min > val ? val : min;
            }
        }
    }
    
    void pop() {
        if (st.top() >= 0)
        {
            st.pop();
        }
        else
        {
            // update min
            min -= st.top();
            st.pop();
        }
    }
    
    int top() {
        if (st.top() < 0)
            return min;
        else
            return min + st.top();
    }
    
    int getMin() {
        return min; 
    }
};
