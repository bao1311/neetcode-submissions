class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for (int num : nums)
        {
            if (mp[num])
                continue;
            mp[num] = mp[num-1] + mp[num+1] + 1; // Sequence formed = left + right + 1
            mp[num-mp[num-1]] = mp[num]; // Left boundary
            mp[num+mp[num+1]] = mp[num]; // Right boundary
            ans = max(ans,mp[num]);
        }
        return ans;
        
    }
};
