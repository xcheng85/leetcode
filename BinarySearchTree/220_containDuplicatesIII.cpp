// C++'s std::set,
// std::set::upper_bound and std::set::lower_bound are equivalent to Java's TreeSet, TreeSet::ceiling and TreeSet::floor, respectively.

class Solution
{
  public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        set<long> window;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k)
                window.erase(nums[i - k - 1]);
                
            auto pos = window.lower_bound((long)nums[i] - t);
            if (pos != window.end() && t >= *pos - nums[i])
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};