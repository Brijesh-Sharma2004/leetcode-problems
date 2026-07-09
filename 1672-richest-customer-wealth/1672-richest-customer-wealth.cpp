class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int maxSum = INT_MIN;

       for(int i=0; i<accounts.size(); i++) {
        int rowSum = 0;
        for(int j=0; j<accounts[i].size(); j++) {
            rowSum = rowSum + accounts[i][j];
        }
        maxSum = max(maxSum , rowSum);
       }
       return maxSum; 
    }
};