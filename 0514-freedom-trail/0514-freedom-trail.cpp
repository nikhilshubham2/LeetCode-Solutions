class Solution {
public:
    int steps(int x, int y, int n){
        int dist = abs(y-x);
        int wrapAround = n - dist;
        return min(dist, wrapAround);
    }
    int solve(int rInd, int kInd, string &ring, string &key, vector<vector<int>> &dp){
        if(kInd == key.size()){
            return 0;
        }
        if(dp[rInd][kInd] != -1) return dp[rInd][kInd];
        int ans = INT_MAX;

        for(int i = 0; i < ring.size(); i++){
            if(ring[i] == key[kInd]){
                int curr = 1 + steps(i, rInd, ring.size()) + solve(i, kInd+1, ring, key, dp);
                ans = min(curr, ans);
            }
        }
        return dp[rInd][kInd] = ans;
    }
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> dp(ring.size(), vector<int>(key.size(), -1));
        return solve(0, 0, ring, key, dp);
    }
};