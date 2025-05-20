class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans(n+1, 0);

        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];

            ans[l] += 1;
            if(r + 1 < n) ans[r+1] -= 1;
        }
        for(int i = 1; i < n; i++){
            ans[i] += ans[i-1];
        }
        for(int i = 0; i < n; i++){
            //nums[i] -= ans[i];
            //if(nums[i] != 0) return false;
            if(nums[i] > ans[i]) return false;
        }
        return true;
    }
};