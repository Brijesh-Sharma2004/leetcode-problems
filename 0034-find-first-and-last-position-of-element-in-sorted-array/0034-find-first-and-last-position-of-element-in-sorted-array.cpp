class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid = 0;
        vector<int> ans(2,-1);

        while(low <= high) {
            mid = low + (high - low) / 2;

            if(nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if(nums[mid] == target) {
                ans[0] = mid;
            }
        }
        
        low = 0, high = nums.size() - 1, mid = 0;
        while(low <= high) {
            mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if(nums[mid] == target) {
                ans[1] = mid;
            }
        }
        return ans;
    }
};