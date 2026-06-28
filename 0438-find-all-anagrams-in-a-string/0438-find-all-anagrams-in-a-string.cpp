class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq_s(26,0) , freq_p(26,0);
        vector<int> ans;
        for(auto c : p) {
            freq_p[c - 'a']++;
        }
        int windowSize = p.size();
        for(int i=0; i<s.size(); i++) {
            freq_s[s[i] - 'a']++;

            if(i >= windowSize) {
                freq_s[s[i - windowSize] - 'a']--;
            }
            if(freq_s == freq_p) {
                ans.push_back(i - windowSize + 1);
            }
        }
        return ans;
    }
};