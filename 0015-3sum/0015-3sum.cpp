class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int s = i+1;
            int e = n-1;
            while(s < e){
                int curr = nums[i] + nums[s] + nums[e];
                if(curr == 0){
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++, e--;
                    while(s < e && nums[s] == nums[s-1]) s++;
                    while(s < e && nums[e] == nums[e+1]) e--;
                }
                else if(curr > 0) e--;
                else s++;
            }
        }
        return ans;
    }
};