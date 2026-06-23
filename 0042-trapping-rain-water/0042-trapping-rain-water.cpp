class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int water = 0;

        while(l < r) {
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);

            if(lmax < rmax) {
                water = water + (lmax - height[l]);
                l++;
            } else {
                water = water + (rmax - height[r]);
                r--;
            }
        }
        return water;

        // vector<int> leftMax(height.size(),0);
        // vector<int> rightMax(height.size(),0);
        // int water = 0;

        // leftMax[0] = height[0];          //Prefix Array approach is used.
        // for(int i=1; i<height.size(); i++) {
        //     leftMax[i] = max(leftMax[i-1],height[i]);
        // }

        // rightMax[height.size() - 1] = height[height.size() - 1]; 
        // for(int i=height.size() - 2; i>=0; i--) {
        //     rightMax[i] = max(rightMax[i+1],height[i]);
        // }

        // for(int i=0; i<height.size(); i++) {
        //     water = water + min(leftMax[i],rightMax[i]) - height[i];
        // }
        // return water;
    }
};