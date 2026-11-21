class Solution {
   private:
    static constexpr int dx[4] = {1, 0, -1, 0};
    static constexpr int dy[4] = {0, -1, 0, 1};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid.front().size();

        queue<pair<int, int>> qu;

        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    qu.push({i, j});
                }
            }
        }

        int ans = 0;
        while (!qu.empty() && fresh > 0) {
            int sz = qu.size();
            ans++;

            while (sz--) {
                auto [r, c] = qu.front();
                qu.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i], nc = c + dy[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            grid[nr][nc] = 2;
                            fresh--;
                            qu.push({nr, nc});
                        }
                    }
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};
