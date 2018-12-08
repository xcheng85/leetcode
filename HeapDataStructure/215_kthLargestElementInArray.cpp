//1. max Heap, 
// build heap o(n) + o(k*lgn) k times pop 

//2. min heap;  
// choose first k element to build heap, and rest n- k  to compare with root
// build k number heap o(k) + o( (n - k) * lg(k))


class Solution
{
  public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (min_heap.size() < k)
            {
                min_heap.push(nums[i]);
            }
            else
            {
                if (min_heap.top() < nums[i])
                {
                    min_heap.pop();
                    min_heap.push(nums[i]);
                }
            }
        }

        return min_heap.top();
    }
};