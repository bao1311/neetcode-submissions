class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int,int>> st;
        int res = 0;
        int startIndex = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            int height = heights[i];
            if (st.size() == 0)
            {
                st.push_back({i,heights[i]});
            }
            else if (st.back().second == height)
            {
                continue;
            }
            else if (st.back().second < height)
            {
                st.push_back({i,height});
            }
            else
            {
                while (!st.empty() && st.back().second >= height)
                {
                    res = max(res,st.back().second * (i - st.back().first));                    
                    startIndex = st.back().first;
                    st.pop_back();
                }
                st.push_back({startIndex,height});
            }
        }
        for (auto p : st)
        {
            cout << p.first << ' ' << p.second << '\n';
        }
        int n = heights.size();
        while (st.size())
        {
            res = max(res,st.back().second*(n - st.back().first));
            st.pop_back();

        }
        return res;
    }
};
