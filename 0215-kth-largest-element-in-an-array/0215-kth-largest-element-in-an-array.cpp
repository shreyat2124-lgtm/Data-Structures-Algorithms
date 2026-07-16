class Solution {
public:
         int findKthLargest(vector<int>& nums, int k)
    {
        // Heap me sirf k largest elements store karenge.
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int num : nums)
        {
            // Har element ko heap me daalo.
            minHeap.push(num);

            // Agar heap me k se zyada elements aa gaye,
            // to smallest element ka koi use nahi hai.
            // Wo kabhi kth largest nahi ban sakta.
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        // Heap ka top hamesha
        // kth largest element hoga.
        return minHeap.top();
    }
};
    