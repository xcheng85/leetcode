class Solution
{
  public:
    int thirdMax(vector<int> &nums)
    {

        priority_queue<int, vector<int>, greater<int>> min_heap;
        unordered_set<int> cache;

        for (int i : nums)
        {
            if (cache.find(i) == cache.end())
            {
                min_heap.push(i);
                cache.insert(i);
                if (min_heap.size() > 3)
                {
                    cache.erase(min_heap.top());
                    min_heap.pop();
                }
            }
        }
        if (min_heap.size() < 3)
        {
            while (min_heap.size() > 1)
            {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};