class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int j = 0, sum = 0, width = 0, currArea = 0, ans = 0;
        stack<int> s;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int>heights(cols,0);
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                } else{
                    heights[j] = 0;
                }
            }
            vector<int> right(cols,-1);
        for(int k=cols-1; k>=0; k--) {   //next smaller 
            while(!s.empty() && heights[s.top()] >= heights[k]) {
                s.pop();
            }
            right[k] = s.empty() ? cols : s.top();
            s.push(k);
        }

        while(!s.empty()) s.pop();

        vector<int> left(cols,-1);
        for(int l=0; l<cols; l++) {     //previous smsller
            while(!s.empty() && heights[s.top()] >= heights[l]) {
                s.pop();
            }
            left[l] = s.empty() ? -1 : s.top();
            s.push(l);
        }

        while(!s.empty()) s.pop();

        for(int m=0; m<cols; m++) {
            width = right[m] - left[m] - 1;
            currArea = heights[m] * width;
            ans = max(ans,currArea);
        }
        }
        // vector<int> right(heights.size(),-1);
        // for(int i=cols-1; i>=0; i--) {   //next smaller 
        //     while(!s.empty() && heights[s.top()] > heights[i]) {
        //         s.pop();
        //     }
        //     right[i] = s.empty() ? cols : s.top();
        //     s.push(i);
        // }

        // while(!s.empty()) s.pop();

        // vector<int> left(heights.size(),-1);
        // for(int i=0; i<cols; i++) {     //previous smsller
        //     while(!s.empty() && heights[s.top()] >= heights[i]) {
        //         s.pop();
        //     }
        //     left[i] = s.empty() ? -1 : s.top();
        //     s.push(i);
        // }

        // for(int i=0; i<heights.size(); i++) {
        //     width = right[i] - left[i] - 1;
        //     currArea = heights[i] * width;
        //     ans = max(ans,currArea);
        // }
        return ans;
    }
};

