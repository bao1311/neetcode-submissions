class Solution {
public:
    int solve(int v, vector<int>& piles, int h)
    {
        int res = 0;
        for (int p : piles)
        {
            res += ceil(double(p)/v);
        }
        return res <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = -1;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (solve(m,piles,h))
            {
                r = m - 1;
                res = m;
            } 
            else
            {
                l = m + 1;
            }
        }
        return res;
    }
};
