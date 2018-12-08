class Solution
{
  public:
    int findKthSmallest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>> max_heap; // default is maxheap for stl
        for (int i = 0; i < nums.size(); i++)
        {
            if (max_heap.size() < k)
            {
                max_heap.push(nums[i]);
            }
            else
            {
                if (max_heap.top() > nums[i])
                {
                    max_heap.pop();
                    max_heap.push(nums[i]);
                }
            }
        }

        return max_heap.top();
    }
};