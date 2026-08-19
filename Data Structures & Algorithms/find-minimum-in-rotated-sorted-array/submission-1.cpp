class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = 1001;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[r])
                return min(nums[l],res);
            else // nums[l] > nums[r]
            {
                if (nums[l] <= nums[m])
                {
                    l = m + 1;
                }
                else
                {
                    res = min(res,nums[m]);
                    r = m-1;
                }
            }
        }
        return res;
        
    }
};
