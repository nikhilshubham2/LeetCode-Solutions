class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int winSize = 2*k+1;

        if(winSize > n) return ans;

        vector<long long> preSum(n+1, 0);
        for(int i = 0; i < n; i++){
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for(int i = k; i < n-k; i++){
            ans[i] = (preSum[i+k+1]-preSum[i-k])/winSize;
        }
        return ans;
    }
};