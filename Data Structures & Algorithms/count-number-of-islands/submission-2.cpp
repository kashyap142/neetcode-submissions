class Solution {
   private:
    using pii = pair<int, int>;
    using vvc = vector<vector<char>>;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(vvc &grid, int x, int y) {
        const int m = grid.size(), n = grid.front().size();
        grid[x][y] = '0';

        for(int i = 0; i < 4; i++) {
            int nr = x + dx[i], nc = y + dy[i];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        const int m = grid.size(), n = grid.front().size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
