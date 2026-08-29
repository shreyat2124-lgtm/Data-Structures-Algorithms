class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;

        int currMax = 0;
        int maxSum = nums[0];

        int currMin = 0;
        int minSum = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            total += nums[i];
            // Normal Kadane
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
            // Minimum Kadane
            currMin = min(nums[i], currMin + nums[i]);
            minSum = min(minSum, currMin);
        }

        // If we remove the minimum subarray,whatever remains is the best wrapping subarray.
        int circularSum = total - minSum;

        // If all numbers are negative, circularSum becomes 0,but the subarray must be non-empty.
        if(maxSum < 0)
            return maxSum;

        return max(maxSum, circularSum);
    }
};

 
   