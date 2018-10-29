class Solution
{
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> current;

        backtracking(nums, 0, current, results);

        return results;
    }

  protected:
    void backtracking(vector<int> &nums, int idx, vector<int> &current, vector<vector<int>> &results)
    {

        results.push_back(current);

        for (int i = idx; i < nums.size(); i++)
        {
            if (i == idx || nums[i] != nums[i - 1])
            {
                current.push_back(nums[i]);
                backtracking(nums, i + 1, current, results);
                current.pop_back();
            }
        }
    }
};