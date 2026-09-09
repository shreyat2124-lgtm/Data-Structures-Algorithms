class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st; int remove=nums.size()-k;
        for (int x : nums) {
            while (!st.empty() && remove > 0 && st.back() > x) {
                st.pop_back();
                remove--;
            }
            
                st.push_back(x);
            
            
        }
       return vector<int>(st.begin(), st.begin() + k);
    }
};
    