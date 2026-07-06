
class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        // Sorting allows us to use
        // the Two Pointer technique.
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int n = nums.size();

        // Fix the first number.
        for(int i=0;i<n;i++)
        {
            // Skip duplicate first numbers.
            // Otherwise we'll get
            // duplicate quadruplets.
            if(i>0 && nums[i]==nums[i-1])
                continue;

            // Fix the second number.
            for(int j=i+1;j<n;j++)
            {
                // Skip duplicate second numbers.
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;

                // Remaining two numbers
                // will be found using
                // Two Pointers.
                int left = j+1;
                int right = n-1;

                while(left < right)
                {
                    // long long prevents overflow.
                    long long sum =
                    (long long)nums[i]
                    + nums[j]
                    + nums[left]
                    + nums[right];

                    // Quadruplet found.
                    if(sum == target)
                    {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        // Move both pointers.
                        left++;
                        right--;

                        // Skip duplicate third numbers.
                        while(left < right &&
                              nums[left] == nums[left-1])
                        {
                            left++;
                        }

                        // Skip duplicate fourth numbers.
                        while(left < right &&
                              nums[right] == nums[right+1])
                        {
                            right--;
                        }
                    }

                    // Need a bigger sum.
                    else if(sum < target)
                    {
                        left++;
                    }

                    // Need a smaller sum.
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};