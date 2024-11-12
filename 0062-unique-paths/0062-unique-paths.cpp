class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        
        for (int i = 0; i < m; i++) {
            vector<int> temp(n,-1);
            for (int j = 0; j < n; j++) {
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    int down = 0;
                    if(i>0) down = prev[j];
                    int right = 0;
                    if(j>0) right = temp[j - 1];
                    temp[j] = down + right;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};