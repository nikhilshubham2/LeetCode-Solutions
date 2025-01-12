class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2) return {};
        sort(changed.begin(), changed.end());

        map<int, int> mp;
        for(auto it: changed){
            mp[it]++;
        }
        vector<int> ans;
        for(auto &it: changed){
            int twice = 2*it;
            if(mp[it] == 0) continue;

            if(mp.find(twice) == mp.end() || mp[twice] == 0){
                return {};
            }
            mp[twice]--;
            mp[it]--;
            ans.push_back(it);
        }
        return ans;
    }
};