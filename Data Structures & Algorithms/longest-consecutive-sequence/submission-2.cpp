class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for (int num:st)
        {
            if (st.find(num-1) != st.end())
                continue;
            int temp = num;
            int cur = 0;
            while (st.contains(temp))
            {
                cur += 1;
                temp += 1;
            }
            ans = max(ans,cur);
        }
        return ans;
        
    }
};
