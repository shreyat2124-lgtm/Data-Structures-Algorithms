class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxdq;
        deque<int> mindq;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Maintain decreasing deque for maximum
            while(!maxdq.empty() && nums[maxdq.back()] <= nums[right])
                maxdq.pop_back();
            maxdq.push_back(right);
            // Maintain increasing deque for minimum
            while(!mindq.empty() && nums[mindq.back()] >= nums[right])
                mindq.pop_back();

            mindq.push_back(right);

            // Window is invalid
            while(nums[maxdq.front()] - nums[mindq.front()] > limit) {
                // Remove left element from max deque if it leaves
                if(maxdq.front() == left)
                    maxdq.pop_front();
                // Remove left element from min deque if it leaves
                if(mindq.front() == left)
                    mindq.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};