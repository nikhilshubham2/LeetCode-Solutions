class Solution {
public:
    void merse(vector<int> &nums, int s, int mid, int end, int &ans){
        vector<int> temp;
        int left = s;
        int right = mid+1;
        int j = mid + 1;
        for (int i = s; i <= mid; i++) {
            while (j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            ans += (j - (mid + 1));
        }
        left = s;
        right = mid + 1;
        while(left <= mid && right <= end){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= end){
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = s; i <= end; i++) {
            nums[i] = temp[i - s];
        }
    }
    void merseSort(vector<int> &nums, int s, int e, int &ans){
        if(s >= e) return ;
        int mid = s + (e - s)/2;
        merseSort(nums, s, mid, ans);
        merseSort(nums, mid+1, e, ans);
        merse(nums, s, mid, e, ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        merseSort(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};