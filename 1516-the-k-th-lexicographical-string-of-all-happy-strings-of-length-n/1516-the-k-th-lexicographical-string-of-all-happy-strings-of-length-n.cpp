class Solution {
public:
    void solve(int &count, string &curr, int n, int k, string &ans){
        if(curr.size() == n){
            count++;
            if(count == k){
                ans = curr;
            }
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(count, curr, n, k, ans);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string ans;
        string curr;
        int count = 0;
        solve(count, curr, n, k, ans);
        return ans;
    }
};