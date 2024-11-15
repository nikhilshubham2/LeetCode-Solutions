class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int count = 1;
        int ans = 0;
        int curr = 1;

        for(int i = 1; i < n; i++){
            if(word[i-1] == word[i]){
                curr++;
            }
            else if(word[i-1] < word[i]){
                curr++;
                count++;
            }
            else{
                count = 1;
                curr = 1;
            }
            if(count == 5) ans = max(ans, curr);
        }
        return ans;
    }
};