class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map <char,int> need;
        unordered_map <char,int> window;
        for(auto c : t) {
            need[c]++;
        }
        int right = 0, left = 0, minlen = INT_MAX, start = 0;
        int required = need.size(), formed = 0;
        while(right < s.size()) {
            char c = s[right];
            window[c]++;

            if(need.count(c) && window[c] == need[c]) {
                formed++;
            }
            while(left <= right && formed == required) {
                if(right-left+1 < minlen) {
                    minlen = right - left + 1;
                    start = left;
                }
                char leftchar = s[left];
                window[leftchar]--;

                if(need.count(leftchar) && window[leftchar] < need[leftchar]) {
                 formed--;   
                }
                left++;
            }
            right++;
        }
        return (minlen == INT_MAX) ? "" : s.substr(start, minlen);
    }
};