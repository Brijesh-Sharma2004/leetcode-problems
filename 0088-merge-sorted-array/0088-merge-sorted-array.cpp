class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1; i>=0; i--) {
            nums1[i+n] = nums1[i];
        }
        for(int i=0; i<n; i++) {
            nums1[i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};