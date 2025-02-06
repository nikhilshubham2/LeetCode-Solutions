class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int w = 0;
        int lMax = height[0], rMax = height[n-1];
        int l = 1, r = n-2;

        while(l <= r){
            if(lMax <= rMax){
                if(height[l] < lMax){
                    w += (lMax - height[l]);
                }
                else lMax = height[l];
                l++;
            }
            else{
                if(height[r] < rMax){
                    w += (rMax - height[r]);
                }
                else rMax = height[r];
                r--;
            }
        }
        return w;
    }
};