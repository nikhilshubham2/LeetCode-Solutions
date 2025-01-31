class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dfs(int i, int j, vector<vector<int>>& grid, int& id){
        if((i < 0 || i >= m) || (j < 0 || j >= n) || grid[i][j] != 1){
            return 0;
        }
        grid[i][j] = id;
        int size = 1;

        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            size += dfs(x, y, grid, id);
        }
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int islandNo = 2;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i, j, grid, islandNo);
                    mp[islandNo] = area;
                    maxArea = max(maxArea, area);
                    islandNo++;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st; // to avoid same island count multiple times
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if((x >= 0 && x < m) && (y >= 0 && y < n) && grid[x][y] != 0){
                            int id = grid[x][y];
                            st.insert(id);
                        }
                    }
                    int islands = 1;
                    for(auto it: st) islands += mp[it];
                    maxArea = max(maxArea, islands);
                }
            }
        }
        return maxArea;
    }
};
