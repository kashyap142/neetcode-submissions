class Solution {
   private:
    using pii = pair<int, int>;
    using vvc = vector<vector<char>>;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void bfs(vvc& grid, int x, int y) {
        const int m = grid.size(), n = grid.front().size();
        queue<pii> qu;
        qu.push({x, y});

        grid[x][y] = '0';

        while (!qu.empty()) {
            int r = qu.front().first, c = qu.front().second;
            qu.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (grid[nr][nc] == '1') {
                        qu.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
                }
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
                    bfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
