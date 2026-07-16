class MedianFinder {
public:

    // Smaller half ke elements.
    priority_queue<int> maxHeap;

    // Larger half ke elements.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {

    }

    void addNum(int num)
    {
        // Decide karo number kis half me belong karta hai.
        if(maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Agar maxHeap me 2 extra elements aa gaye,
        // to uska largest element minHeap me shift kar do.
        if(maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Agar minHeap bada ho gaya,
        // to uska smallest element maxHeap me le aao.
        // Median hamesha beech me maintain rahega.
        else if(minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        // Dono halves equal hain.
        // Median = dono middle elements ka average.
        if(maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // Odd elements ke case me
        // extra element hamesha maxHeap me rakha gaya hai.
        return maxHeap.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */