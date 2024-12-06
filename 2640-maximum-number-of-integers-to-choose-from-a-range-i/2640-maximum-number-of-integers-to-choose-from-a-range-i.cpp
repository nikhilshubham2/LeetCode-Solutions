class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        unordered_set<int> st(banned.begin(), banned.end());
        int sum = 0;

        for(int i = 1; i <= n; i++){
            if(st.find(i) == st.end()){
                if(sum + i <= maxSum){
                    sum += i;
                    count++;
                }
            }
            if(sum >= maxSum) break;
        }
        return count;
    }
};