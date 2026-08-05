class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int left = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] > left)
                {
                    k -= 1;
                }
                else if (nums[j] + nums[k] < left)
                {
                    j += 1;
                }
                else
                {
                    // cout << 'a';
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while (j < nums.size() - 1 && nums[j] == nums[j+1])
                    {
                        j += 1;
                    }
                    while (k > 0 && nums[k] == nums[k-1])
                    {
                        k -= 1;
                    }
                    j++;
                    k--;
                }
            }

        }
        return ans;
    }
};
