class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low < high) {
            int mid = low + (high - low) / 2;

            int Sum = 0 , countSubarray = 1;

            for(auto num : nums) {
            if(Sum + num <= mid) {
               Sum += num;
            } else {
                countSubarray++;
                Sum = num;
            }
            }
            if(countSubarray <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};