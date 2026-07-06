# Count Inversions Using Merge Sort

## Problem Description
Count the number of inversions in an array. An inversion is a pair of indices (i, j) where i < j but arr[i] > arr[j].

## Examples
- Input: [1, 5, 0, 3, 4, 5]
- Output: 3
- Inversions: (1,0), (5,3), (5,4)

## Approach
Use the **Divide and Conquer** paradigm with **Merge Sort** to efficiently count inversions in O(n log n) time.

### Algorithm Steps:

1. **Apply Merge Sort Recursively**: Divide the array into two halves until base case (single element or two elements).

2. **During Merge Step**:
   - If `arr[left] <= arr[right]`: Place `arr[left]` into temp array and move `left++`. No inversion.
   - If `arr[left] > arr[right]`: Place `arr[right]` into temp array. Since the left half is already sorted, ALL elements from `arr[left]` to `arr[mid]` form inversions with `arr[right]`. Add `(mid - left + 1)` to the inversion count and move `right++`.

3. **Copy Remaining Elements**: Copy any remaining elements from left or right half into the temp array.

4. **Copy Back**: Copy the merged sorted elements back into the original array.

5. **Total Inversion Count** is the sum of:
   - Inversions in the left half
   - Inversions in the right half
   - Inversions across both halves (counted during merge)

## Complexity Analysis
- **Time Complexity**: O(n log n) - Merge sort time complexity
- **Space Complexity**: O(n) - For the temp array during merge

## Key Insight
During the merge process, when we find an element from the right half that is smaller than an element from the left half, we know that this element forms inversions with ALL remaining elements in the left half (since they are sorted). This is why we add `(mid - left + 1)` to the count instead of counting inversions one by one.
