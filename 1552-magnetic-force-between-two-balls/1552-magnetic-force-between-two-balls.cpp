class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int low = 1, ans = 0;
        sort(position.begin(), position.end());
        int high = position[position.size() - 1] - position[0];

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int ball = 1, lastplaced = position[0];

            for(int i=1; i<position.size(); i++) {
                if(position[i] - lastplaced >= mid) {
                    ball++;
                    lastplaced = position[i];
                }
            }
            if(ball >= m) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};