class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);
        int step = 0;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; i++){
                int curr = q.front();
                q.pop();
                if(curr == n-1) return step;

                int left = curr-1, right = curr+1;
                if(left >= 0 && vis[left] != 1){
                    q.push(left);
                    vis[left] = 1;
                }
                if(right <= n-1 && vis[right] != 1){
                    q.push(right);
                    vis[right] = 1;
                }
                for(auto it: mp[arr[curr]]){
                    if(vis[it] != 1){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
                mp[arr[curr]].clear();
            }
            step++;
        }
        return -1;
    }
};