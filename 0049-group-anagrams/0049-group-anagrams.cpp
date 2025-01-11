class Solution {
public:
    string getString(string s){
        int mp[26] = {0};
        for(char ch: s){
            mp[ch-'a']++;
        }
        string ans = "";
        for(int i = 0; i < 26; i++){
            if(mp[i] != 0){
                while(mp[i]-- > 0){
                    ans += ('a' + i);
                }
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            string mapping = getString(s);
            mp[mapping].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};