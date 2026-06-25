class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(),bloomDay.end()); 

        if(1LL * m * k > bloomDay.size()) return -1;

        while(low < high) {
            int mid = low + (high - low) / 2;

            int consecutive = 0, bouquets = 0;

            for(int i=0; i<bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) {
                    consecutive++;

                    if(consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                    }
                } else {
                    consecutive = 0;
                }
            }
            if(bouquets >= m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};