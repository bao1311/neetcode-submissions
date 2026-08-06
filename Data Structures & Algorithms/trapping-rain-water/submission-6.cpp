class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        vector<int> lMax(n, 0);
        vector<int> rMax(height.size(), 0);
        lMax[0] = height[0];
        rMax[rMax.size()-1] = height.back();
        for (int i = 1; i < n; ++i)
        {
            lMax[i] = max(lMax[i-1], height[i]);
        }

        for (int i = n-2; i >= 0; --i)
        {
            rMax[i] = max(rMax[i+1],height[i]);
        }

        for (int i = 0; i < height.size(); ++i)
        {
            res += min(lMax[i],rMax[i]) - height[i];            
        }
        return res;
    }
};
