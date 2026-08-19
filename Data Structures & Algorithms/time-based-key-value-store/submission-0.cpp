class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        int l = 0;
        int r = mp[key].size() - 1;
        while (l <= r)
        {
            int m = l + (r - l)/2;
            if (mp[key][m].second <= timestamp)
            {
                l = m + 1;
                res = mp[key][m].first;
            }
            else
            {
                r = m - 1;
            }
        }
        return res;
    }
};
