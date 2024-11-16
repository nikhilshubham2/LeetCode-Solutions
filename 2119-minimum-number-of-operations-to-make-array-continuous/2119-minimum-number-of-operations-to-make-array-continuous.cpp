class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n-1;
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        int m = nums.size();

        for(int i = 0; i < m; i++){
            int minRange = nums[i];
            int maxRange = minRange + n-1;
            
            auto count = upper_bound(nums.begin(), nums.end(), maxRange) - nums.begin();
            
            int curr = count - i;
            ans = min(ans, n - curr);
        }
        return ans;
    }
};