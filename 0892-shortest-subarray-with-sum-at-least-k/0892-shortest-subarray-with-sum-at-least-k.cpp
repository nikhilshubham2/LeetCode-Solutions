class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<long long> preSum(n+1, 0);
        int res = INT_MAX;

        for(int i = 0; i < n; i++){
            preSum[i+1] = preSum[i] + nums[i];
        }
        for(int j = 0; j <= n; j++){
            while(!q.empty() && preSum[j] - preSum[q.front()] >= k){
                res = min(res, j-q.front());
                q.pop_front();
            }
            while(!q.empty() && preSum[j] <= preSum[q.back()]) q.pop_back();
            q.push_back(j);
        }
        return res == INT_MAX ? -1 : res;
    }
};
