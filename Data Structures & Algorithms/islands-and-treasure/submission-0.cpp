class Solution {
   private:
    int m, n, INF = INT_MAX;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size(), n = grid.front().size();

        queue<pair<int, int>> qu;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    qu.push({i, j});
                }
            }
        }

        int d = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            d++;
            while (sz--) {
                auto [r, c] = qu.front();
                qu.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dx[i], nc = c + dy[i];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == INF) {
                            grid[nr][nc] = d;
                            qu.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
};
