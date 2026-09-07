class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        unordered_set<int> st;
        vector<int> ans;
        for (int x : nums) {
            if (st.find(x) != st.end()) {
                ans.push_back(x);
            }
            st.insert(x);
        }
        return ans;
    }
};