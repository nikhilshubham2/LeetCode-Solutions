class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> prefLeft(n);
        vector<int> prefRight(n);

        prefLeft[0] = (s[0] == '0');
        prefRight[n-1] = (s[n-1] == '1');

        for(int i=1; i<n; i++){
            prefLeft[i] = prefLeft[i-1] + (s[i] == '0');
        }
        for(int i=n-2; i>=0; i--){
            prefRight[i] = prefRight[i+1] + (s[i] == '1');
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            ans = max(ans, prefLeft[i]+prefRight[i+1]);
        }
        return ans;
    }
};