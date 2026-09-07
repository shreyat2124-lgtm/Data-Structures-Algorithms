class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            int index = x - 1;
            nums[index] = -abs(nums[index]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};