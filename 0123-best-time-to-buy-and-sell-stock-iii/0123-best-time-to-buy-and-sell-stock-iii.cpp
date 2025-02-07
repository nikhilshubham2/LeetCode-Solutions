class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, 
                                        vector<int> (3, -1)));
        // Covering the base cases
        // if times == 0, return 0
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 2; j++){
                dp[i][j][0] = 0;
            }
        }
        // if ind == n, return 0
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                dp[n][i][j] = 0;
            }
        }
        // we could have avoided it just by initilizing the dp with 0
        // but to learn how to initilize base case, i have done so


        for(int ind = n - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int time = 1; time <= 2; time++){
                    int profit = 0;
                    if(buy){
                        profit = max(dp[ind+1][buy][time], 
                                    -prices[ind] + dp[ind+1][!buy][time]);
                    }
                    else{
                        profit = max(dp[ind+1][buy][time], 
                                    prices[ind] + dp[ind+1][!buy][time-1]);
                    }
                    dp[ind][buy][time] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};