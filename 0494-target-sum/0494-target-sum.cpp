class Solution {
public:
    int solve(int ind, int target, vector<int>& nums,  vector<vector<int>> &dp){
        if(ind == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[ind]) return 1;
            return 0;
        }
        //if(nums[ind] > target) return 0;
        if (dp[ind][target] != -1) return dp[ind][target];

        int notPick = solve(ind-1, target, nums, dp);
        int pick = 0;
        if (nums[ind] <= target) pick = solve(ind-1, target - nums[ind], nums, dp);
        return dp[ind][target] = pick + notPick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if(sum - target < 0) return 0;
        if((sum - target) % 2 == 1) return 0;
        int s2 = (sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        return solve(n - 1, s2, nums, dp);
    }
};