#include <bits/stdc++.h>
using namespace std;

// Merge two sorted halves
// and count the inversions formed between them.
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    // Left half starts from 'low'
    int left = low;

    // Right half starts just after mid
    int right = mid + 1;

    // Stores inversions found during this merge
    int cnt = 0;

    // STEP 1
    // Merge both sorted halves
    while(left <= mid && right <= high)
    {
        // Left element is smaller.
        // No inversion.
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Right element is smaller.
        // Inversion found.
        else
        {
            temp.push_back(arr[right]);

            // Since left half is already sorted,
            // every remaining element from 'left' to 'mid'
            // will also be greater than arr[right].

            cnt += (mid - left + 1);

            right++;
        }
    }

    // STEP 2
    // Copy remaining left half
    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // STEP 3
    // Copy remaining right half
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // STEP 4
    // Copy merged array back
    // into the original array.
    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];
    }

    return cnt;
}

// Merge Sort
// Returns inversion count
int mergeSort(vector<int> &arr, int low, int high)
{
    // Base case
    if(low >= high)
    {
        return 0;
    }

    int mid = (low + high) / 2;

    int cnt = 0;

    // STEP 1
    // Count inversions
    // in left half
    cnt += mergeSort(arr, low, mid);

    // STEP 2
    // Count inversions
    // in right half
    cnt += mergeSort(arr, mid+1, high);

    // STEP 3
    // Count inversions
    // between both halves
    cnt += merge(arr, low, mid, high);

    return cnt;
}

// Driver Function
int numberOfInversions(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n-1);
}
