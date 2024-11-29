class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(m, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, 0, 0}); // (t, r, c)

        while(!q.empty()){
            auto cur = q.top();
            int t = q.top()[0], r = q.top()[1], c = q.top()[2];
            q.pop();
            if(r == m - 1 && c == n - 1) return t;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                if((nr >= 0 && nr < m) && (nc >= 0 && nc < n) && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    int gridTime = grid[nr][nc];
                    int wait = (gridTime - t) % 2 == 0 ? 1 : 0;
                    int time = max(gridTime + wait, t+1);
                    q.push({time, nr, nc});
                }
            }
        }
        return -1;
    }
};