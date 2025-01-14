class SummaryRanges {
public:
    unordered_set<int> st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> num(st.begin(), st.end());
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        int n = num.size();

        for(int i = 0; i < n; i++){
            int l = num[i];
            while(i < n-1 && num[i]+1 == num[i+1]){
                i++;
            }
            ans.push_back({l, num[i]});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */