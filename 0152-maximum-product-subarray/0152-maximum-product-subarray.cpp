class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int mx = nums[0];
        int mn = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int oldMx = mx;
            int oldMn = mn;
            mx = max({x, oldMx * x, oldMn * x});
            mn = min({x, oldMx * x, oldMn * x});
            ans = max(ans, mx);
        }

        return ans;
    }
};