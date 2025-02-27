class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> vec1, vec2;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1){
                    vec1.push_back({i, j});
                }
                if(img2[i][j] == 1){
                    vec2.push_back({i, j});
                }
            }
        }
        map<pair<int, int>, int> mp;
        int ans = 0;
        for(auto i: vec1){
            for(auto j: vec2){
                int x = i.first - j.first;
                int y = i.second - j.second;
                mp[{x, y}]++;
                ans = max(ans, mp[{x, y}]);
            }
        }
        return ans;
    }
};