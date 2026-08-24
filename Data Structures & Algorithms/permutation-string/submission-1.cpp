class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int need[26] = {0};
        int supply[26] = {0};

        for (auto c : s1)
        {
            need[c-'a'] += 1;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); ++r)
        {
            supply[s2[r]-'a']+=1;
            while (r-l+1 > s1.size())
            {
                supply[s2[l]-'a']-=1;
                l+=1;
            }
            bool all = true;
            for (int i = 0; i < 26; ++i)
            {
                if (supply[i]!=need[i])
                {
                    all = false;
                    break;
                }
            }
            if (all)   
                return true;
        }
        return false;
    }
};
