class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        for(int i=0; i<k; i++) {
            sum = sum + nums[i];
        }
        double maxsum = sum;
        //double maxavg = sum / k;
        for(int i=1; i<=n-k; i++) {
            sum = sum - nums[i-1] + nums[i+k-1];
            //double curravg = sum / k;
            maxsum = max(sum,maxsum);
        }
        return maxsum / k;
    }
};