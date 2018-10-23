class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        if (s.size() == 1)
            return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();)
        {
            if (s.size() - i <= max_len / 2)
                break;
            int j = i, k = i;
            while (k < s.size() - 1 && s[k + 1] == s[k])
                ++k; // Skip duplicate characters.
            i = k + 1;
            while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
            {
                ++k;
                --j;
            } // Expand.
            int new_len = k - j + 1;
            if (new_len > max_len)
            {
                min_start = j;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }

    string longestPalindrome(string s)
    {
        if (s == null || s.size() < 1)
            return "";
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end + 1);
    }

    int
    expandAroundCenter(string s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};

public
String longestPalindrome(String s)
{
    int n = s.size();
    string res;

    vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);

            if (dp[i][j] && (res == null || j - i + 1 > res.length()))
            {
                res = s.substring(i, j + 1);
            }
        }
    }

    return res;
}