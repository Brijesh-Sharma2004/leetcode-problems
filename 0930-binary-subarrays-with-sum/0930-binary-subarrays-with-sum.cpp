class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        
        int left = 0, subarray = 0, sum = 0;

        for(int right=0; right<nums.size(); right++) {
            sum = sum + nums[right];

            while(sum > goal) {
                sum = sum - nums[left];
                left++;
            }
            subarray = subarray + (right - left + 1);
        }
        return subarray;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);

        // unordered_map <int,int> mpp;
        // int count = 0, sum = 0;
        // mpp[0] = 1;
        // for(int right=0; right<nums.size(); right++) {
        //     sum = sum + nums[right];
            
        //     if(mpp.find(sum - goal) != mpp.end()) {
        //         count = count + mpp[sum - goal];
        //     }
        //     mpp[sum]++;
        // }
        // return count;
    }
};