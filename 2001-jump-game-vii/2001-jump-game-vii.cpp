class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1] != '0') return false;
        queue<int> q;
        int farthest = 0;
        
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == n-1) return true;
            for(int i = max(curr + minJump, farthest); i <= min(curr + maxJump, n-1); i++){
                if(s[i] == '0'){
                    q.push(i);
                }

            }
            farthest = max(farthest, curr + maxJump + 1);
        }
        return false;
    }
};