/* Now think in a simpler way first, if you have only one update operation, suppose input is (n = 5, updates = { {1, 3, 2} }), what does the O(n + k) solution do?

Initialize the result array as length of n + 1, because we will operate on endIndex + 1:
result = [0, 0, 0, 0, 0, 0]
Then marks index 1 as 2 and marks index 3+1 as -2:
result = [0, 2, 0, 0, -2, 0]
Next, iterate through result, and accumulates previous sum to current position, just like 303. Range Sum Query - Immutable:
result = [0, 0 + 2, 0 + 2, 0 + 2, 2 + (-2), 0] = [0, 2, 2, 2, 0, 0]
Finally, trivial work to discard the last element because we don't need it:
result = [0, 2, 2, 2, 0], which is the final result. */

class Solution
{
  public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        vector<int> result(length + 1, 0);
        for (auto &e : updates)
        {
            result[e[0]] += e[2];
            result[e[1] + 1] -= e[2]; // key
        }

        // do range sum
        for (int i = 1; i < length; ++i)
        {
            result[i] += result[i - 1];
        }

        result.pop_back();
        return result;
    }
};