/*  Longest Word in Dictionary through Deleting */

class Solution
{
  public:
    string findLongestWord(string s, vector<string> &d)
    {
        string max_str = "";
        for (auto& str : d)
        {
            if (isSubsequence(str, s))
            {
                if (str.size() > max_str.size() || (str.size() == max_str.size() && str < max_str))
                    max_str = str;
            }
        }
        return max_str;
    }

  private:
    // x is the subsequence of y
    bool isSubsequence(string x, string y)
    {
        int j = 0;
        for (int i = 0; i < y.size() && j < x.size(); i++)
            if (x[j] == y[i])
                j++;
        return j == x.size();
    }
};