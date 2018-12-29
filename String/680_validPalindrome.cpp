#include <string>

class Solution
{
  public:
    bool validPalindrome(string s)
    {
        return valid(s, 0, s.length() - 1, 1);
    }

  private:
    // d, max charater allowed to be deleted
    bool valid(string &s, int i, int j, int d)
    { // d: num of chars you can delete at most
        if (i >= j)
            return true;
        if (s[i] == s[j])
            return valid(s, i + 1, j - 1, d);
        else
            return d > 0 && (valid(s, i + 1, j, d - 1) || valid(s, i, j - 1, d - 1));
    }
};

class Solution
{
  public:
    bool validPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j])
                return isp(s, i + 1, j) || isp(s, i, j - 1);
        return true;
    }

  private:
    bool isp(string s, int l, int r)
    {
        for (int i = l, j = r; i < j; i++, j--)
            if (s[i] != s[j])
                return false;
        return true;
    }
};