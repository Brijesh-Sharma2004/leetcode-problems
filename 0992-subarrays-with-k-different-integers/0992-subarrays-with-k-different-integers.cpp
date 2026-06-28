class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map <int,int> mpp;
        int left = 0, result = 0;
        for(int right=0; right<nums.size(); right++) {
            if(mpp[nums[right]] == 0) k--;
            mpp[nums[right]]++;

            while(k < 0) {
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) {
                    k++;
                }
                left++;
            }
            result = result + (right - left + 1);
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};