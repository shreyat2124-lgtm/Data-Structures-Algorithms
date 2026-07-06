class Solution {
public:

    // Stores the final answer.
    int cnt = 0;

    // -----------------------------
    // Merge two sorted halves.
    // Exactly the same merge function
    // used in Count Inversions.
    // -----------------------------
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        // Merge both sorted halves.
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining left half.
        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining right half.
        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        // Put the sorted elements
        // back into the original array.
        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
    }

    // --------------------------------
    // Count reverse pairs BEFORE merging.
    // Both halves are already sorted.
    // --------------------------------
    void countPairs(vector<int>& nums, int low, int mid, int high)
    {
        // Start checking from
        // the first element
        // of the right half.
        int right = mid + 1;

        // Check every element
        // in the left half.
        for(int left=low; left<=mid; left++)
        {
            // Keep moving right
            // while reverse pair exists.
            while(right <= high &&
                  nums[left] > 2LL * nums[right])
            {
                right++;
            }

            // Every element before 'right'
            // forms a reverse pair
            // with nums[left].
            cnt += right - (mid + 1);
        }
    }

    // Normal Merge Sort.
    void mergeSort(vector<int>& nums, int low, int high)
    {
        if(low >= high)
            return;

        int mid = (low + high)/2;

        // Solve left half.
        mergeSort(nums, low, mid);

        // Solve right half.
        mergeSort(nums, mid+1, high);

        // Count reverse pairs
        // between both halves.
        countPairs(nums, low, mid, high);

        // Finally merge.
        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums)
    {
        cnt = 0;

        mergeSort(nums,0,nums.size()-1);

        return cnt;
    }
};