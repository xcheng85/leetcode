#include <vector>
using namespace std;

// if the set is keep growing , we have to allocate the entire tree and update count in each node
// waste a lot of space 


struct SegmentTreeNode
{
    // state of node is number of 
    int count; // lcm in this range
    int start;
    int end;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int lcm, int s, int e) : lcm(lcm),
                                             start(s),
                                             end(e),
                                             left(nullptr),
                                             right(nullptr)
    {
    }
};

class MedianFinder
{
  public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
    }

    double findMedian()
    {
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */