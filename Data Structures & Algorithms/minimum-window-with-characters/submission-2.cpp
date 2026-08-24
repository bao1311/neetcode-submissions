class Solution {
public:

    int need[256] = {0};
    int supply[256] = {0};
    bool good()
    {
        for (int i = 0; i < 256; ++i)
        {
            if (supply[i] < need[i])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        for (int i = 0; i < t.size(); ++i)
        {
            need[(unsigned char)t[i]] += 1;
        }
        int l = 0;
        int res = INT_MAX;
        int bestL = 0;
        int matched = 0;
        string ans = "";
        for (int r = 0; r < s.size(); ++r)
        {
            supply[(unsigned char)s[r]] += 1;
            if (supply[(unsigned char)s[r]] <= need[(unsigned char)s[r]])
            {
                matched += 1;
            }
            while (matched == t.size())
            {
                if (r-l+1 < res)
                {
                    res = r - l + 1;
                    bestL = l;
                }
                supply[(unsigned char)s[l]] -= 1;
                if (supply[(unsigned char)s[l]] < need[(unsigned char)s[l]])
                {
                    matched -= 1;
                }
                l+=1;
            }
        }
        // cout << res << ' ' << bestL << '\n';
        if (res == INT_MAX)
        {
            return "";
        }
        return s.substr(bestL,res);
    }
};
