class Solution {
public:
    int bfs(vector<int> adj[], int n){
        unordered_set<int> st;
        queue<int> q;
        q.push(0);
        st.insert(0);

        int level = 0;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int node = q.front();
                q.pop();
                if(node == n-1) return level;
                for(auto it: adj[node]){
                    if(st.find(it) == st.end()){
                        q.push(it);
                        st.insert(it);
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[n];
        for(int i = 0; i < n-1; i++){
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            int d = bfs(adj, n);
            ans.push_back(d);
        }
        return ans;
    }
};