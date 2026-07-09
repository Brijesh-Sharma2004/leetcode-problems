class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=0; i+1<nums.size(); i++) {
            nums[i+1] = nums[i] + nums[i+1];
        }
        return nums;
    }
};