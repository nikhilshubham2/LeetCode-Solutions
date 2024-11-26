class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        int ans = -1, count = 0;

        for(auto it: edges){
            indegree[it[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                ans = i;
                count++;
            }
        }
        return count > 1 ? -1: ans;
    }
};