class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target)
                high = mid;
            else
                low = mid + 1;
        }
        int first = low;
        // Target does not exist
        if(first == nums.size() || nums[first] != target)
            return {-1, -1};
        low = 0;
        high = nums.size();

       
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] > target)
                high = mid;
            else
                low = mid + 1;
        }
        int last = low - 1;
        return {first, last};
    }
};