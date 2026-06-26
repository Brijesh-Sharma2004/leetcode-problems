class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minsum = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            sum = sum + nums[i];
            while(sum >= target) {
                minsum = min(minsum,i-left+1);
                sum = sum - nums[left];
                left++;
            }
        }
        return (minsum == INT_MAX) ? 0 : minsum;
    }
};