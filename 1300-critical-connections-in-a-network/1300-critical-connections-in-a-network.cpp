class Solution {
public:
    int time = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[],
    vector<int> &firstVis, vector<int> &lowestTime, vector<vector<int>> &ans){
        vis[node] = 1;
        firstVis[node] = time;
        lowestTime[node] = time;
        time++;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, firstVis, lowestTime, ans);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
                if(lowestTime[it] > firstVis[node]){
                    ans.push_back({it, node});
                }
            }
            else{
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> firstVis(n, 0);
        vector<int> lowestTime(n, 0);
        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1, vis, adj, firstVis, lowestTime, ans);

        return ans;
    }
};