class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        long long sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        long long maxs = sum;
        for(int i = k; i < nums.size(); i++) {
            sum = sum + nums[i] - nums[i-k];
            maxs = max(maxs, sum);
        }

        return (double)maxs / k;
    }
};