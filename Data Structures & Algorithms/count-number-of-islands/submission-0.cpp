class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Find all connected components and find disconnected components
        // Using dfs
        // Find the first 1

        int island_count = 0;

        // unordered_set<pair<int, int>> lands;
        for (int r = 0; r < size(grid); r++){
            for (int c = 0; c < size(grid[0]); c++) {
                if (grid[r][c] == '1'){ 
                    dfs(r,c, grid);
                    island_count++;
                }
            }
        }

        return island_count;
    }

private:
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if (!in_bounds(x,y,grid)) return;
        if(grid[x][y] == '0' ) return;
        grid[x][y] = '0'; // Visited

        dfs(x, y+1, grid); dfs(x, y-1, grid); dfs(x-1, y, grid); dfs(x+1, y, grid);
    }

    bool in_bounds(int i, int j, vector<vector<char>>& grid) {
        return (i >= 0 && j >= 0 && i < size(grid) && j < size(grid[0]));
    }
};
