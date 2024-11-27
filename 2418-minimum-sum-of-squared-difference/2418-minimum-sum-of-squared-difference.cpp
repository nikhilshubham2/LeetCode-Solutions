class Solution {
public:
    long long solve(long long diff, vector<long long> &ans){
        long long reduce = 0;
        for(auto it : ans){
            if(it > diff){
                reduce += (it - diff);
            }
        }
        return reduce;
    }

    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = abs(nums1[i] - nums2[i]);
        }

        long long left = 0, right = *max_element(ans.begin(), ans.end());
        long long k = static_cast<long long>(k1) + k2;
        long long maxDiff = 0, remK = 0;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long operation = solve(mid, ans);

            if(operation <= k){
                maxDiff = mid;
                remK = k - operation;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        priority_queue<long long> q;
        for(auto it: ans){
            q.push(min(it, maxDiff));
        }
        while(remK > 0 && !q.empty()){
            long long curr = q.top();
            q.pop();

            if (curr == 0) break;

            long long next = q.empty() ? 0 : q.top();
            long long reduce = min(curr - next + 1, remK);
            q.push(curr - reduce);
            remK -= reduce;
        }

        long long result = 0;
        while(!q.empty()){
            long long val = q.top();
            q.pop();
            result += val * val;
        }
        return result;
    }
};
