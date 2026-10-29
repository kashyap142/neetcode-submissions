class Solution {
    final int[] dx = {1, 0, -1, 0};
    final int[] dy = {0, -1, 0, 1};

    private void bfs(char[][] grid, boolean[][] vis, int i, int j) {
        final int m = grid.length;
        final int n = grid[0].length;
        Queue<int[]> qu = new LinkedList<>();

        qu.offer(new int[] {i, j});
        vis[i][j] = true;

        while (!qu.isEmpty()) {
            int[] front = qu.poll();
            int r = front[0], c = front[1];

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                // these should be within boundaries
                // these should be non visited and '1'

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (!vis[nr][nc] && grid[nr][nc] == '1') {
                        vis[nr][nc] = true;
                        qu.offer(new int[] {nr, nc});
                    }
                }
            }
        }
    }

    public int numIslands(char[][] grid) {
        final int m = grid.length;
        final int n = grid[0].length;

        /*
        have a queue to check for possible movements
        have a list to check if visited & island('1')
        */

        boolean[][] vis = new boolean[m][n];

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return ans;
    }
}
