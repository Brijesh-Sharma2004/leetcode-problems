class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, odd = 0, subarray = 0, count = 0;

        for(int right=0; right<nums.size(); right++) {
            if(nums[right] % 2 != 0) {
                odd++;
                count = 0;
            }

            while(odd > k) {
                if(nums[left] % 2 != 0) {
                    odd--;
                }
                left++;
            }
            while(odd == k && nums[left] % 2 == 0) {
                left++;
                count++;
            }
            if(odd == k) {
            subarray = subarray + count + 1;
            }
        }
        return subarray;
    }
};