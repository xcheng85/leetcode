// insert sort o(n2)
// self-blanced bst. root is median
//heap data structure

class MedianFinder
{
    priority_queue<int> lo;                            // max heap higherhalf
    priority_queue<int, vector<int>, greater<int>> hi; // min heap lowerhalf

  public:
    // Adds a number into the data structure.
    void addNum(int num)
    {
        lo.push(num); // Add to max heap

        // self balancing step
        hi.push(lo.top()); // balancing step
        lo.pop();

        // maining low size >= high size
        if (lo.size() < hi.size())
        { // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian()
    {
        return lo.size() > hi.size() ? (double)lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};