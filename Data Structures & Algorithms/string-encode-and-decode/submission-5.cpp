class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto s : strs)
        {
            ans += to_string(s.length()) + '#' + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> tokens;
        int i = 0;
        while (i < s.size())
        {
            string token = "";
            int j = i;
            while (s[j] != '#')
            {
                j += 1;
            }
            int len = stoi(s.substr(i,j+1));
            j += 1;
            while (len--)
            {
                token += s[j];
                j += 1;
            }
            tokens.push_back(token);
            i = j;

        }
        return tokens;
    }
};
