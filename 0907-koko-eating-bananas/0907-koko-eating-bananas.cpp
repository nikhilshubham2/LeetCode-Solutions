class Solution {
public:
    bool canEat(vector<int>& piles, int h, int hour){
        long long int total = 0;
        for(int i = 0; i < piles.size(); i++){
            total += piles[i]/hour;
            if(piles[i]%hour != 0) total++;
        }
        return (total <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int end = *max_element(piles.begin(), piles.end());
        int mid = 0;
        while(s <= end){
            mid = s + (end-s)/2;
            bool hour = canEat(piles, h, mid);
            if(hour){
                end = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return s;
    }
};