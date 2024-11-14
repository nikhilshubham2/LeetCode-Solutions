class Solution {
public:
    bool possible(vector<int>& quantities, int n, int mid){
        int count = 0;
        for(auto it: quantities){
            count += it/mid;
            if(it%mid) count++;
            if(count > n) return 0;
        }
        return 1;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1;
        int e = *max_element(quantities.begin(), quantities.end());
        int ans = -1;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(possible(quantities, n, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};