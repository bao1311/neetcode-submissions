class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> mp;
        int l = 0;
        vector<int> res;
        priority_queue<pair<int,int>> heap;
        for (int r = 0; r < nums.size(); ++r)
        {
            heap.push({nums[r],r});
            if (r >= k - 1)
            {
                // cout << "in";
                // auto [v,idx] = heap.top();
                // cout << "v,idx: " << v << ' ' << idx << '\n';
                while (heap.top().second < r - k + 1)
                {
                    // cout << 'a' << '\n';
                    heap.pop();
                }

                // cout << "top,idx: " <<  heap.top().first << ' ' << heap.top().second << '\n';
                // cout << "----------\n";
                res.push_back(heap.top().first);
            }
        }
        return res;
    }
};
