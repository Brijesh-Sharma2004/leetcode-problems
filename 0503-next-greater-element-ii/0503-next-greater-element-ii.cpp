class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n,-1);

        for(int i=0; i<2 * n; i++) {
            int curr = nums[i % n];

            while(!s.empty() && nums[s.top()] < curr) {
                ans[s.top()] = curr;
                s.pop();
            }
            if(i < n) {
            s.push(i);
            }
        }
        return ans;
    }
};