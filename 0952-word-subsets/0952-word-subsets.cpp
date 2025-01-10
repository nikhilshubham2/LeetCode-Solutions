class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<char> mp(26, 0);
        for(auto it: words2){
            vector<char> temp(26, 0);
            for(auto ch: it){
                temp[ch-'a']++;
                mp[ch-'a'] = max(temp[ch-'a'], mp[ch-'a']);
            }
        }
        for(auto it: words1){
            vector<char> temp(26, 0);
            for(auto ch: it){
                temp[ch-'a']++;
            }
            bool res = true;
            for(int i = 0; i < 26; i++){
                if(mp[i] > temp[i]){
                    res = false;
                    break;
                }
            }
            if(res) ans.push_back(it);
        }
        return ans;
    }
};