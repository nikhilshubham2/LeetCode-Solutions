class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        long long sum = 0;
        int n = nums.size();
        int i = 0;

        while(i < k && i < n){
            mp[nums[i]]++;
            sum += nums[i];
            i++;
        }
        if(mp.size() == k) ans = sum;

        while(i < n){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]] == 0) mp.erase(nums[i-k]);

            sum += nums[i];
            sum -= nums[i-k];

            if(mp.size() == k) ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};