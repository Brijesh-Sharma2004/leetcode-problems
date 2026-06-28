class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int,int> mpp;
        int left = 0, maxlen = 0;
        for(int i=0; i<fruits.size(); i++) {
            mpp[fruits[i]]++;
            while(mpp.size() > 2) {
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen,i-left+1);
        }
        return maxlen;
    }
};