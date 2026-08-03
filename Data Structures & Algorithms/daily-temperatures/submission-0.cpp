class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for (int i = 0; i < temperatures.size(); ++i)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    int cur = st.top();
                    st.pop();
                    ans[cur] = i-cur;
                } 
                st.push(i);
    
            }

        }
        return ans;
    }
};
