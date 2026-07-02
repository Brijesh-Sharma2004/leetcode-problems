class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;

        for(int i=0; i<nums.size(); i++) {
            //mpp[nums[i]] = i;
            if(mpp.find(nums[i]) != mpp.end()) {
                return true;
            }
            mpp[nums[i]] = i;
        }
        return false;
        //   sort(nums.begin(), nums.end());

        //   for(int i=0; i + 1<nums.size(); i++) {
        //     if(nums[i] == nums[i+1]) {
        //         return true;
        //     }
        //   }
        //   return false;
    }
};