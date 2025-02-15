class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto it: nums){
            if(it % 2 == 0) sum += it;
        }
        vector<int> ans;
        for(auto it: queries){
            int val = it[0];
            int ind = it[1];

            if(nums[ind] % 2 == 0) sum -= nums[ind];
            nums[ind] += val;
            if(nums[ind] % 2 == 0) sum += nums[ind];
            ans.push_back(sum);
        }
        return ans;
    }
};