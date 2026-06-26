class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left = 0;
        int maxlen = 0;
        for(int right=0; right<s.size(); right++) {
           char ch = s[right];

           if(mpp.find(ch) != mpp.end()) {
            left = max(left,mpp[ch] + 1);
           }
           mpp[ch] = right;
           maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};