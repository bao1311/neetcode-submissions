class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int temp = INT_MAX;
    void dfs(vector<vector<int>>& grid,int x,int y,int dist)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() 
        || grid[x][y] == -1 || grid[x][y] == 0)
        {
            return;
        }
        if (dist<grid[x][y])
        {
            grid[x][y] = dist;
            for (int i = 0; i < 4; ++i)
            {
                dfs(grid,x+dx[i],y+dy[i],dist+1);
            }
        }


    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> ans(rows,vector<int>(cols,0));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 0)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        dfs(grid,i+dx[k],j+dy[k],1);
                    }
                }
            }
        }

    }
};
