class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        
        // x, y, currentLength, remaining k
        queue<vector<int>> q;
        q.push({0,0,0,k});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int x = it[0], y = it[1];            
            if(x < 0 || x >= m || y < 0 || y >= n) continue;            
            if(x == m-1 && y == n-1) return it[2];
             
            if(grid[x][y] == 1){
                if(it[3] > 0) it[3]--;
                else continue;
            }            
            if(visited[x][y]!=-1 && visited[x][y] >= it[3])  continue;            
            visited[x][y] = it[3];
                
            q.push({x+1, y, it[2]+1, it[3]});
            q.push({x-1, y, it[2]+1, it[3]});
            q.push({x, y+1, it[2]+1, it[3]});
            q.push({x, y-1, it[2]+1, it[3]});
        }
        
        return -1;
    }
};