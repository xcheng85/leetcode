//brutal force

class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int result = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++)
        {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--)
            { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++)
            { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }
            result += min(max_left, max_right) - height[i];
        }
        return result;
    }
};

public:
int trap(vector<int> &height)
{
    if (height == null)
        return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++)
    {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++)
    {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
