class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(), 0);

        while(low < high) {
            int mid = low + (high - low) / 2;

            int sum = 0, D = 1;

            for(auto weight : weights) {
                if(sum + weight <= mid) {
                    sum += weight;
                } else {
                    D++;
                    sum = weight;
                }
            }
            if(D <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};