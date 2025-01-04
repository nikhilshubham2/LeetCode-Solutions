class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            int x = st.top();
            if(x != -1 && s[i] == ')' && s[x] == '('){
                st.pop();
                len = max(len, i - st.top());
            }
            else st.push(i);
        }
        return len;
    }
};