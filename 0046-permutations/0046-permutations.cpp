class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> st;
    vector<int> temp;
    int n;
    void solve(vector<int> &nums){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(st.find(nums[i]) == st.end()){
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                solve(nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums);
        return ans;
    }
};