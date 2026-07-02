class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int first = nums[i];
            int second = target - first;
            if(mpp.find(second) != mpp.end()) {
               ans.push_back(i);
               ans.push_back(mpp[second]);
            }
            mpp[first] = i;
        }
        return ans;
    }
};