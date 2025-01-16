class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> N(n, 0);
        vector<int> Y(n, 0);
        
        for(int i = 1; i < n; i++){
            if(customers[i-1] == 'N'){
                N[i] = N[i-1]+1;
            }
            else N[i] = N[i-1];
        }

        if(customers[n-1] == 'Y') Y[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(customers[i] == 'Y'){
                Y[i] = Y[i+1] + 1;
            }
            else Y[i] = Y[i+1];
        }
        int minPenalty = 1e9;
        int ind = -1;

        for(int i = 0; i < n; i++){
            int curr = N[i] + Y[i];
            if(curr < minPenalty){
                minPenalty = curr;
                ind = i;
            }
        }
        
        int countN = count(customers.begin(), customers.end(), 'N');
        if(countN < minPenalty) return n;
        return ind;
    }
};