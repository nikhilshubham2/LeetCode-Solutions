class Solution {
public:
    int solve(int l, int r, vector<int> &arr, vector<vector<int>> &dp){
        if(l == r) return dp[l][r] = 0;
        if(dp[l][r] != -1) return dp[l][r];

        int ans = INT_MAX;
        for(int i = l; i < r; i++){
            int left = solve(l, i, arr, dp);
            int right = solve(i+1, r, arr, dp);

            int leftMax = *max_element(arr.begin()+l, arr.begin()+i+1);
            int rightMax = *max_element(arr.begin()+i+1, arr.begin()+r+1);

            int curr = left + right + leftMax*rightMax;

            ans = min(ans, curr);
        }
        return dp[l][r] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, arr, dp);
    }
};