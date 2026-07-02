class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        set<int> st(nums.begin(),nums.end());
        
        int longest = 1;
        int count = 1;

        auto it = st.begin();
        auto prev = it;
        it++;

        while(it != st.end()) {
            if(*it == *prev + 1) {
                count++;
            } else {
                count = 1;
            }
            longest = max(longest,count);
            prev = it;
            it++;
        }
        return longest;
    }
};