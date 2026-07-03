class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        





        // int lastNonZero = 0;

        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i] != 0) {
        //         nums[lastNonZero] = nums[i];
        //         lastNonZero++;
        //     }
        // }
        // for(int i=lastNonZero; i<nums.size(); i++) {
        //     nums[i] = 0;
        // }



        // for(int i=0; i<nums.size(); i++) {
        //     if(0 == nums[i] ) {
        //         nums.push_back(nums[i]);
        //         nums.erase(nums.begin() + i);
        //     }
        // }
    }
};