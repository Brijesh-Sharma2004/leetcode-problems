class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int count = 0, prefixSum = 0;

        for(int i=0; i<nums.size(); i++) {
            prefixSum = prefixSum + nums[i];
            if(mpp.find(prefixSum - k) != mpp.end()) {
                count = count + mpp[prefixSum - k];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};