class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_set<int> st(spaces.begin(), spaces.end());
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(st.find(i) != st.end()){
                ans.push_back(' '); 
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};