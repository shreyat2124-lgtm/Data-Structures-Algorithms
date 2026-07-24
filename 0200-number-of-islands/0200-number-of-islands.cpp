class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        // Grid ke bahar chale gaye.
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return;

        // Water hai ya already visit kar chuke hain.
        if(grid[i][j] == '0')
            return;

        // Land ko visit kar diya.
        grid[i][j] = '0';

        // 4 directions me DFS.
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int count = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                // Naya island mila.
                if(grid[i][j] == '1')
                {
                    count++;

                    // Pura island visit kar do.
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};