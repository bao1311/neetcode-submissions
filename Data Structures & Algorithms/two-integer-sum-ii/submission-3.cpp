class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ans(2,0);
        while (l < r)
        {
            int cur = numbers[l] + numbers[r];
            if (cur > target)
                r -= 1;
            else if (cur < target)
                l += 1;
            else
            {
                ans[0] = l+1;
                ans[1] = r+1;
                break;
            }
        }
        return ans;
    }
};
