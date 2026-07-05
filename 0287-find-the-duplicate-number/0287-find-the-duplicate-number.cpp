class Solution {
public:

    int findDuplicate(vector<int>& nums)
    {
        // STEP 1
        // Find a meeting point inside the cycle

        int slow = nums[0];
        int fast = nums[0];

        do
        {
            // Move one step
            slow = nums[slow];

            // Move two steps
            fast = nums[nums[fast]];

        }while(slow != fast);

        // STEP 2
        // Start one pointer from the beginning

        slow = nums[0];

        // Move both one step at a time

        while(slow != fast)
        {
            slow = nums[slow];

            fast = nums[fast];
        }

        // Both pointers meet
        // at the duplicate number

        return slow;
    }
};