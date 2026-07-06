# 645. Set Mismatch (Missing and Duplicate Number)

[LeetCode 645 - Set Mismatch](https://leetcode.com/problems/set-mismatch)

Difficulty: Easy / Medium (varies by approach)

---

Problem: Given an array nums representing numbers from 1 to n where one number is missing and one number appears twice, find and return the repeating number and the missing number as a pair: [repeating, missing].

Example:

Input: [1,2,2,4]

Output: [2,3]

---

Approach (XOR / Bit manipulation):

1. XOR all array elements and all numbers from 1..n. The result xr = Missing ^ Repeating.
2. Find a set bit in xr (rightmost set bit) to partition numbers into two groups where Missing and Repeating differ.
3. XOR elements in each group separately (for both array and 1..n). Each group will yield either Missing or Repeating.
4. Determine which is repeating by counting occurrences in the input array.

This approach uses constant extra space (O(1)) and runs in O(n) time.

---

Complexity:
- Time: O(n)
- Space: O(1)

---

Solution (C++):

```cpp
class Solution {
public:

    vector<int> findTwoElement(vector<int>& arr)
    {
        int n = arr.size();

        // STEP 1
        // XOR all the array elements
        // and all the numbers from 1 to n.
        //
        // Every number appearing once cancels itself.
        // Finally,
        //
        // xr = Missing ^ Repeating

        int xr = 0;

        for(int i=0;i<n;i++)
        {
            xr ^= arr[i];
            xr ^= (i+1);
        }

        // STEP 2
        // Find the rightmost set bit.
        //
        // Missing and Repeating differ at this bit.
        // This bit will help us separate them
        // into two different groups.

        int bitNo = xr & ~(xr - 1);

        // STEP 3
        // Divide both the array elements
        // and numbers from 1 to n
        // into two buckets.
        //
        // Bucket 1 -> Bit is SET.
        // Bucket 2 -> Bit is NOT SET.

        int zero = 0;
        int one = 0;

        for(int i=0;i<n;i++)
        {
            // Check current array element

            if(arr[i] & bitNo)
            {
                one ^= arr[i];
            }
            else
            {
                zero ^= arr[i];
            }

            // Check current number (i+1)

            if((i+1) & bitNo)
            {
                one ^= (i+1);
            }
            else
            {
                zero ^= (i+1);
            }
        }

        // After XORing,
        //
        // one of these variables stores
        // the repeating number
        //
        // the other stores
        // the missing number.
        //
        // We still don't know which is which.

        // STEP 4
        // Count how many times 'zero'
        // appears in the array.

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            if(arr[i] == zero)
            {
                cnt++;
            }
        }

        // If zero occurs twice,
        // it is the repeating number.

        if(cnt == 2)
        {
            return {zero, one};
        }

        // Otherwise,
        // one is repeating
        // and zero is missing.

        return {one, zero};
    }
};
```
