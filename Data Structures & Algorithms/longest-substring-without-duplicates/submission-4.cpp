class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        if (s.size() == 0)
            return 0;
        int ans = 0;
        int alpha[256] = {0};
        for (int r = 0; r < s.size(); ++r)
        {
            while (l < r && alpha[(unsigned char)s[r]] > 0)
            {
                alpha[(unsigned char)s[l]] -= 1;
                l += 1;
            }
            alpha[(unsigned char)s[r]] += 1;
            ans = max(ans, r-l+1);
            
        }
        return ans;
        

    }
};
