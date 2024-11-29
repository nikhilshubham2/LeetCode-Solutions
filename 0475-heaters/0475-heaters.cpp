class Solution {
public:
    bool solve(vector<int>& houses, vector<int>& heaters, int radius){
        int i = 0, j = 0;
        int m = houses.size();
        int n = heaters.size();

        while(i < m){
            if(j == n) return false;
            int left = heaters[j] - radius;
            int right = heaters[j] + radius;
            if(houses[i] < left || houses[i] > right) j++;
            else i++;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int s = 0;
        int e = max(*max_element(houses.begin(),houses.end()),
                    *max_element(heaters.begin(),heaters.end()));
        int ans = 0;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(solve(houses, heaters, mid)){
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
};