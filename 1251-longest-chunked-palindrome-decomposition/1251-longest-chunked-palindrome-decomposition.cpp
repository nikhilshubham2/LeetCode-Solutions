class Solution {
public:
    int longestDecomposition(string text) {
        string a = "", b = "";
        int count = 0;
        int s = 0, e = text.size()-1;

        while(s < e){
            a += text[s];
            b = text[e] + b;
            if(a == b){
                count++;
                a = "";
                b = "";
            }
            s++;
            e--;
        }
        count = count*2;
        if(a == "" && s > e) return count;

        return count+1;
    }
};
