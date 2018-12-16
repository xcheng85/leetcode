/* Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"] */

#include <vector>

class Solution
{
    void backtrack(string &s, int i, vector<string> &res)
    {
        if (i == s.size())
        {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i]))
        {
            // toggle case
            s[i] ^= (1 << 5); // 32 
            backtrack(s, i + 1, res);
        }
    }

  public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};