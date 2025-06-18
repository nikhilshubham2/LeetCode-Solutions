class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % 3) return {};
        sort(nums.begin(), nums.end());

        int i = 0;
        vector<vector<int>> ans;

        while(i + 2 < n){
            if(nums[i+2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
            i += 3;
        }
        return ans;
    }
};