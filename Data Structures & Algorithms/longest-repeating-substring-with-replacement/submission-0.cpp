class Solution {
public:
    int characterReplacement(string s, int k) {
        int alpha[27] = {0};
        int l = 0;
        int res = 0;
        int maxFreq = 0;
        for (int r = 0; r < s.size(); ++r)
        {
            alpha[s[r] - 'A']++;
            maxFreq = max(maxFreq,alpha[s[r] - 'A']);
            while (r-l+1 - maxFreq > k)
            {
                alpha[s[l]-'A'] -= 1;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
