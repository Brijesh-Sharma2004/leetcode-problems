class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> answer(n,0);
        for(int i=0; i<n; i++) {
            int previndex = 0;
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                previndex = s.top();
                answer[previndex] = i - previndex;
                s.pop();
            }
            s.push(i);
        }
        return answer;
    }
};