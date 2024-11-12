class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int s = nums.size();
        if(s == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int ans = 1;
        for(int i = 1; i < s; i++){
            if(nums[i] == nums[i-1]+1){
                ans++;
            }
            else if(nums[i] != nums[i - 1]){
                maxLen = max(maxLen, ans);
                ans = 1;
            }
        }
        return max(maxLen, ans);
    }
};