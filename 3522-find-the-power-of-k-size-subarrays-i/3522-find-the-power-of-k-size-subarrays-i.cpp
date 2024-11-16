class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1, -1);
        if(k > n) return ans;

        int count = 1;
        for(int i = 1; i < k; i++){
            if(nums[i-1] == nums[i]-1){
                count++;
            }
            else count = 1;
        }
        if(count == k) ans[0] = nums[k-1];
        int i = 1;
        int j = k;

        while(j < n){
            if(nums[j-1] == nums[j]-1){
                count++;
            }
            else count = 1;

            if(count >= k){
                ans[i] = nums[j];
            }
            i++;
            j++;
        }
        return ans;
    }
};