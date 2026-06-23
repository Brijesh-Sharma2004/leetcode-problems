class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        if(nums.empty()) return 0;
        stack<int> s;
        
        vector<int> prevsmll(nums.size(),-1);
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            prevsmll[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();

        vector<int> nxtsmll(nums.size(),-1);
        for(int i=nums.size() - 1; i>=0; i--) {
            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            nxtsmll[i] = s.empty() ? nums.size() : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();

        vector<int> prevgrt(nums.size(),-1);
        for(int i=0; i<nums.size(); i++) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            prevgrt[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();

        vector<int> nxtgrt(nums.size(),-1);
        for(int i=nums.size() - 1; i>=0; i--) {
            while(!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            nxtgrt[i] = s.empty() ? nums.size() : s.top();
            s.push(i);
        }

        long long total = 0;
        for(int i=0; i<nums.size(); i++) {
            long long leftmin = i - prevsmll[i];
            long long rightmin = nxtsmll[i] - i;
            long long mincontribute = nums[i] * leftmin * rightmin;

            long long leftmax = i - prevgrt[i];
            long long rightmax = nxtgrt[i] - i;
            long long maxcontribute = nums[i] * leftmax * rightmax;

            total = total + maxcontribute - mincontribute;
        }
        return total;
    }
};