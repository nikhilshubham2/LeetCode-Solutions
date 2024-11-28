class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int dx = x + dRow[j];
                    int dy = y + dCol[j];

                    if((dx >= 0 && dx < m) && (dy >= 0 && dy < n) &&
                    dist[x][y] + grid[dx][dy] < dist[dx][dy]){
                        dist[dx][dy] = dist[x][y] + grid[dx][dy];
                        q.push({dx, dy});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};