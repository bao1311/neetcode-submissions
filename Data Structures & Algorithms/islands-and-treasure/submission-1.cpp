class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
   

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,0));
        queue<pair<int,int>> q;
    
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                int x = row + dx[i];
                int y = col + dy[i];
                // Can't pass
                if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != INT_MAX) 
                    continue;
                grid[x][y] = grid[row][col] + 1;
                q.push({x,y});
            }

        }

    }
};
