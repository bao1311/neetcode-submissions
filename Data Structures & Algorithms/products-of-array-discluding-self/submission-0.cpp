class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> up;
        vector<int> down;
        int cur = 1;
        for (auto num : nums)
        {
            cur *= num;
            up.push_back(cur);
        }
        cur = 1;
        for (auto it = nums.rbegin(); it != nums.rend(); ++it)
        {
            cur *= (*it);
            down.push_back(cur);
        }
        reverse(down.begin(),down.end());
        vector<int> res;
        res.push_back(down[1]);
        for (int i = 1; i < nums.size()-1; ++i)
        {
            res.push_back(up[i-1] * down[i+1]);
        }
        res.push_back(up[nums.size()-2]);
        return res; 

    }
};
