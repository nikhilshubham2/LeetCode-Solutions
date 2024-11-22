class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int countRows = 0;

        map<vector<int>,int> mp;
        for(auto &row: matrix)  mp[row]++;

        for(auto &row: matrix){
            vector<int>invertedRow(m);

            for(int i = 0; i < m; i++) invertedRow[i] = (row[i]==1) ? 0 : 1;
            
            int currRowsCount = mp[row] + mp[invertedRow];
            countRows = max(countRows, currRowsCount);
        }
        return countRows;
    }
};