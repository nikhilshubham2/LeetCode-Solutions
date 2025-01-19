class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                            greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            vis[i][0] = 1;
            vis[i][n-1] = 1;
            q.push({heightMap[i][0], {i, 0}});
            q.push({heightMap[i][n-1], {i, n-1}});
        }

        for(int i = 0; i < n; i++){
            vis[0][i] = 1;
            vis[m-1][i] = 1;
            q.push({heightMap[0][i], {0, i}});
            q.push({heightMap[m-1][i], {m-1, i}}); 
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        int ans = 0;

        while(!q.empty()){
            auto it = q.top(); q.pop();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i < 4; i++){
                int nr = dx[i] + r;
                int nc = dy[i] + c;

                if((nr >= 0 && nr < m) && (nc >= 0 && nc < n) && vis[nr][nc] == 0){
                    ans += max(h - heightMap[nr][nc], 0);
                    int maxH = max(h, heightMap[nr][nc]);
                    q.push({maxH, {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};