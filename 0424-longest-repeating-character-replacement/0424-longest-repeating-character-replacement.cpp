class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int maxfreq = 0, left = 0, maxlen = 0;

        for(int right=0; right<s.size(); right++) {
            mpp[s[right]]++;
            maxfreq = max(maxfreq,mpp[s[right]]);

            if((right-left+1) - maxfreq > k) {
                mpp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};