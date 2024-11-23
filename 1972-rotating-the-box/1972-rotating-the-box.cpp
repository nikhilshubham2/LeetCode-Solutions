class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int r = box.size();
        int c = box[0].size();
        vector<vector<char>> ans(c, vector<char>(r, '.'));

        for(int i = 0; i < r; i++){
            int bottom = c-1;
            for(int j = c - 1; j >= 0; j--){
                if(box[i][j] == '#'){
                    ans[bottom][r-i-1] = '#';
                    bottom--;
                }
                else if(box[i][j] == '*'){
                    ans[j][r-i-1] = '*';
                    bottom = j-1;
                }
            }
        }
        return ans;
    }
};
