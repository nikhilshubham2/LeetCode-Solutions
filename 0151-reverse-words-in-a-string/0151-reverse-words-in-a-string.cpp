class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        int size = s.size();
        int i = 0;
        while(i < size && s[i] == ' ') i++;
        for(int j = i; j < size; j++){
            if(s[j] == ' ' && temp.size() == 0) continue;
            else if(s[j] == ' ' && temp.size() != 0){
                ans = temp + ' ' + ans;
                temp = "";
            }
            else temp += s[j];
        }
        ans = temp + ' ' + ans;
        size = ans.size();
        i = 0;
        while(i < size && ans[i] == ' ') i++;
        int j = size-1;
        while(j >= 0 && ans[j] == ' ') j--;

        return ans.substr(i, j-i+1);
    }
};