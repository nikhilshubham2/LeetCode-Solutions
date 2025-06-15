class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxNum = s;
        string minNum = s;

        for(auto it: s){
            if(it != '9'){
                for(auto &ch: maxNum){
                    if(ch == it){
                        ch ='9';
                    }
                }
                break;
            }
        }
        if(s[0] != '1'){
            char curr = s[0];
            for(auto &it: minNum){
                if(it == curr) it = '1';
            }
            return stoi(maxNum) - stoi(minNum);
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i] != '0' && s[i] != '1'){
                char curr = s[i];
                for(auto &it: minNum){
                    if(it == curr){
                        it = '0';
                    }
                }
                break;
            }
        }
        return stoi(maxNum) - stoi(minNum);
    }
};