class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        //grid[x][y] == 0 -> free
        //grid[x][y] == 1 -> gaurd
        //grid[x][y] == 2 -> wall
        //grid[x][y] == 3 -> guarded

        for(auto it: guards){
            grid[it[0]][it[1]] = 1;
        }
        for(auto it: walls){
            grid[it[0]][it[1]] = 2;
        }

        for(auto it: guards){
            int x = it[0], y = it[1];

            //upper direction
            for(int i = x-1; i >= 0; i--){
                if(grid[i][y] == 1 || grid[i][y] == 2) break;
                grid[i][y] = 3;
            }
            //lower direction
            for(int i = x+1; i < m; i++){
                if(grid[i][y] == 1 || grid[i][y] == 2) break;
                grid[i][y] = 3;
            }
            //left
            for(int i = y-1; i >= 0; i--){
                if(grid[x][i] == 1 || grid[x][i] == 2) break;
                grid[x][i] = 3;
            }
            //right
            for(int i = y+1; i < n; i++){
                if(grid[x][i] == 1 || grid[x][i] == 2) break;
                grid[x][i] = 3;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};