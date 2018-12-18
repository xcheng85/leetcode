// overlapping subproblem duplicates

// abcde bcde cde d e

#include <vector>

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int ll = s.size();

        int dict = wordDict.size();

        vector<bool> dp(ll + 1, false); // substring[0, i] is breakable

        dp[0] = true; // empty string is breakable

        for (int i = 0; i < ll + 1; i++)
        {
            for (int j = 0; j < dict; j++)
            {
                if (dp[i]) // substr [0, i] is breakable, concat all the candidates and update dp table
                {
                    string str = s.substr(i, wordDict[j].size());
                    if (str == wordDict[j])
                    {
                        dp[i + wordDict[j].size()] = true;
                    }
                }
            }
        }
        return dp[ll];
    }
};
