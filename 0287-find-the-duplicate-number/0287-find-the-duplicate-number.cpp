class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;


        // sort(nums.begin(), nums.end());
        // int ans;
        // for(int i=0; i<nums.size(); i++) {
        //    if(nums[i] == i+1) {
        //      ans = nums[i];
        //    }
        // }
        // return ans;
    }
};