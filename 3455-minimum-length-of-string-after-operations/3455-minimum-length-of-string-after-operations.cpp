class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for(auto it: s) mp[it]++;

        for(auto &it: mp){
            if(it.second >= 3){
                while(it.second > 2) it.second -= 2;
            }
        }
        int count = 0;
        for(auto it: mp) count += it.second;
        return count;
    }
};