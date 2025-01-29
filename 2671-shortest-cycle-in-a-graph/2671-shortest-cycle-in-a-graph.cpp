class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(dist[it] == -1){
                        dist[it] = dist[node] + 1;
                        q.push(it);
                    }
                    else if(dist[it] >= dist[node]){
                        ans = min(ans, dist[node] + dist[it] + 1);
                    }
                }
            }
        }
        return  ans == 1e9 ? -1 : ans;
    }
};