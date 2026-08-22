class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int ans = 0;
        for (int r = 1; r < prices.size(); ++r)
        {
            // EXPAND with r++ already
            
            // SHRINK
            while (l < r && prices[l] >= prices[r])
            {
                l += 1;
            }
            // RECORD
            ans = max(ans, prices[r] - prices[l]);
        }
        return ans;
    }
};
