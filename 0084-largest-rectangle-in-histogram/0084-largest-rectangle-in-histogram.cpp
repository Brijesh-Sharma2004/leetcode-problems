class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        stack<int> s;
        int ans = 0, currArea = 0, width = 0;
        vector<int> right(heights.size(),-1);
        for(int i=heights.size()-1; i>=0; i--) {   //next smaller 
            while(!s.empty() && heights[s.top()] > heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? heights.size() : s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        vector<int> left(heights.size(),-1);
        for(int i=0; i<heights.size(); i++) {     //previous smsller
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        for(int i=0; i<heights.size(); i++) {
            width = right[i] - left[i] - 1;
            currArea = heights[i] * width;
            ans = max(ans,currArea);
        }
        return ans;
    }
};