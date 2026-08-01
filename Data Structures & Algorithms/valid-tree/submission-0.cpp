class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1)
            return false;
        vector<vector<int>> adj(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        function<bool(int,int)> helper = [&](int node, int parent)
        {
            visited.insert(node);
            for (auto t : adj[node])
            {
                if (t == parent)
                    continue;
                if (visited.find(t) != visited.end() || !helper(t,node))
                    return false;
            }
            return true;
        };
        if (!helper(0,-1))
            return false;
        return visited.size() == n;
    }
};
