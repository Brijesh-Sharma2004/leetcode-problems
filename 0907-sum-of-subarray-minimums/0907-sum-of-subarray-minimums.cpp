class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        if (arr.empty()) return 0;

        stack<int> s1;
        stack<int> s2;
        vector<int> left(arr.size(),0);
        long long result = 0, contribution = 0;
        int mod = 1e9 + 7;

        for(int i=0; i<arr.size(); i++) {
            while(!s1.empty() && arr[s1.top()] >= arr[i]) {
                s1.pop();
            }
            if(s1.empty()) {
                left[i] = i + 1;      //PSE
            } else {
            left[i] = i - s1.top();
            }
            s1.push(i);
        }
        vector<int> right(arr.size(),0);
        for(int i=arr.size() - 1; i>=0; i--) {
            while(!s2.empty() && arr[s2.top()] > arr[i]) {
                s2.pop();
            }
            if(s2.empty()) {
                right[i] = arr.size() - i;     //NSE
            } else {
            right[i] = s2.top() - i;
            }
            s2.push(i);
        }
        for (int i = 0; i < arr.size(); i++) {
            contribution = 1LL * arr[i] * left[i] * right[i];
            result = (result + contribution) % mod;
        }
        return result;
    }
};