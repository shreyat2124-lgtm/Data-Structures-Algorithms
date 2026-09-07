class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<int, int> mp;
      int ans = 0;
        for (int a : nums1) {
            for (int b : nums2) {
                mp[a + b]++;
            }
        }
        for (int c : nums3) {
            for (int d : nums4) {

                int need = -(c + d);

                if (mp.find(need) != mp.end())
                    ans += mp[need];
            }
        }
        return ans;
    }
};