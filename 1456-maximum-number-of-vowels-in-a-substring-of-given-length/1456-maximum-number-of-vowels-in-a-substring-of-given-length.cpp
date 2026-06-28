class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int count = 0, maxcount = 0;

        for(int i=0; i<s.size(); i++) {
            if(vowels.count(s[i])) {
                count++;
            }
            if(i>=k && vowels.count(s[i-k])) {
                count--;
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};