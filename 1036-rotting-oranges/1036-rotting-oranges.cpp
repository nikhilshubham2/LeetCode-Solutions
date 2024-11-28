class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        //{time, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(row, vector<int>(col, 0));
    
        int freshOranges = 0; // Count of fresh oranges

        // Enqueue rotten oranges and mark them as visited
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                }
                else if(grid[i][j] == 1) freshOranges++;
            }
        }

        // If there are no fresh oranges, return 0
        if(freshOranges == 0) return 0;

        // Direction arrays for exploring neighbors
        int d_row[] = {-1, 0, 1, 0};
        int d_col[] = {0, 1, 0, -1};
    
        int time = 0;
        // Perform BFS
        while(!q.empty()){
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            time = max(time, t);
            for(int i = 0; i < 4; i++){
                int n_row = r + d_row[i];
                int n_col = c + d_col[i];
                //check validity of neightbours, if they are in region and not visited
                if((n_row >= 0 && n_row < row) && (n_col >= 0 && n_col < col) &&
                    visited[n_row][n_col] == 0 && grid[n_row][n_col] == 1){
                        q.push({t+1, {n_row, n_col}});
                        visited[n_row][n_col] = 1;
                        freshOranges--;
                        if(freshOranges == 0){
                            return t+1;
                        }
                    }
            }
        }
        return -1;
    }
};