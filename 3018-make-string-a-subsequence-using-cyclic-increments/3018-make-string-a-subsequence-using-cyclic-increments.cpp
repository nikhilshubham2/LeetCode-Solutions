class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        int s1 = str1.size();
        int s2 = str2.size();

        while(i < s1 && j < s2){
            if(str1[i] == str2[j] || str1[i]+1 == str2[j] || str1[i]-25 == str2[j]){
                j++;
            }
            i++;
        }
        return j == s2;
    }
};