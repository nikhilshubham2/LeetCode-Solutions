class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % 3) return {};
        sort(nums.begin(), nums.end());

        int i = 0, j = 0;
        vector<vector<int>> ans;
        vector<int> temp;

        while(i < n){
            if(temp.size() == 0){
                temp.push_back(nums[i]);
                i++;
            }
            else if(nums[i] - temp[0] <= k){
                temp.push_back(nums[i]);
                i++;
            }
            else if(nums[i] - temp[0] > k) return {};
            if(temp.size() == 3){
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};