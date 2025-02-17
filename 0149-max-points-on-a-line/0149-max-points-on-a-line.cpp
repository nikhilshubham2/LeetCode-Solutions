class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<double, int> mp;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                double slope;
                if(dx == 0) slope = INT_MAX;
                else slope = (double)dy/dx;
                mp[slope]++;
            }

            for(auto it: mp){
                ans = max(it.second+1, ans);
            }
        }
        return ans;
    }
};