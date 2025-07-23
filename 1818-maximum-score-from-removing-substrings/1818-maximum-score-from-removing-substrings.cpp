class Solution {
public:
    int solve(string &s, string &remove, int point){
        int n = s.size();
        stack<char> st;
        int val = 0;

        for(char ch: s){
            if(!st.empty()){
                if(st.top() == remove[0] && ch == remove[1]){
                    st.pop();
                    val += point;
                }
                else st.push(ch);
            }
            else st.push(ch);
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return val;
    }

    int maximumGain(string s, int x, int y) {
        string s1 = "ab";
        string s2 = "ba";
        if(y > x){
            swap(s1, s2);
            swap(x, y);
        }

        return solve(s, s1, x) + solve(s, s2, y);
    }
};