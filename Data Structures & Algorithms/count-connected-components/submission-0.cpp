class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        int ans = 0;

        function<void(int)> dfs = [&](int i)
        {
            if (visited.find(i) != visited.end())
                return;
            visited.insert(i);
            for (auto neighbor : adj[i])
            {
                dfs(neighbor);
            }
        };
        for (int i = 0; i < n; ++i)
        {
            if (visited.find(i) != visited.end())
                continue;
            dfs(i);
            ans += 1;
        }
        return ans;
    }
};
