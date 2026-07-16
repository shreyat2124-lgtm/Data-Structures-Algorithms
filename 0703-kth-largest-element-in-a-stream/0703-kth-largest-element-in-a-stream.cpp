class KthLargest {
public:
    // Heap me sirf k largest elements store karenge.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int k;

    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;

        // Pehle se diye hue elements bhi stream ka part hain.
        // Isliye unhe bhi ek-ek karke process karo.
        for(int num : nums)
        {
            add(num);
        }
    }

    int add(int val)
    {
        // Har naya element pehle heap me daal do.
        minHeap.push(val);

        // Agar k se zyada elements ho gaye,
        // to smallest element ka koi use nahi hai.
        // Wo kabhi kth largest nahi ban sakta.
        if(minHeap.size() > k)
        {
            minHeap.pop();
        }

        // Heap ka top hamesha
        // kth largest element hoga.
        return minHeap.top();
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */