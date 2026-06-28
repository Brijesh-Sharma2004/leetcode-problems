class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq_s1(26,0) , freq_window(26,0);

        for(auto c : s1) {
            freq_s1[c - 'a']++;
        }
        int windowSize = s1.size();
        for(int i=0; i<s2.size(); i++) {
            freq_window[s2[i] - 'a']++;

            if(i >= windowSize) {
                freq_window[s2[i - windowSize] - 'a']--;
            }
            if(freq_s1 == freq_window) return true;
        }
        return false;
    }
};