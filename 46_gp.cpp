

class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        unordered_set<int> myset;
        vector<int> current;

        backtracking(nums, myset, current, result);

        return result;
    }

    void backtracking(vector<int> &nums, unordered_set<int> &visited, vector<int> current, vector<vector<int>> &result)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (visited.find(nums[i]) == visited.end())
                {
                    visited.insert(nums[i]);
                    vector<int> tmp = current;
                    tmp.push_back(nums[i]);
                    backtracking(nums, visited, tmp, result);
                    visited.erase(nums[i]);
                }
            }
        }
    }
};