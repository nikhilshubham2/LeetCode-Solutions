class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n-1;
        while(r > 0 && arr[r-1] <= arr[r]) r--;

        int l = 0;
        int ans = r;
        while(l < r && (l == 0 || arr[l-1] <= arr[l])){
            while(r < n && arr[r] < arr[l]){
                r++;
            }
            ans = min(ans, r-l-1);
            l++;
        }
        return ans;
    }
};