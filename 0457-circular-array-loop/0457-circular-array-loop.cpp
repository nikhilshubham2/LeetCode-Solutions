class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int> &path, vector<int> &vis){
        vis[node] = 1;
        path[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, path, vis)){
                    return true;
                }
            }
            else if(path[it]) return true;
        }
        path[node] = 0;
        return false;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            int next = (((nums[i] + i))%n + n)%n;
            if(next != i && nums[i] * nums[next] > 0){
                adj[i].push_back(next);
            }
        }
        vector<int> vis(n, 0), path(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(dfs(i, adj, path, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};