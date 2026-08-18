class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            while (!st.empty() && height[i] >= height[st.top()])
            {
                int mid = st.top();
                st.pop();
                if (!st.empty())
                {
                    int r = height[i];
                    int l = height[st.top()];
                    int h = min(r,l) - height[mid];
                    int w = i - st.top() - 1;
                    res += (w * h);
                }
            }
            st.push(i);
        }
        return res;
    }
};
