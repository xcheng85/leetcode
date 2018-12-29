class Solution
{
  public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> cache;

        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (cache.find(s[i]) != cache.end())
            {
                cache.erase(s[i]);
                count++;
            }
            else
            {
                cache[s[i]]++;
            }
        }
        if (!cache.empty())
            return count * 2 + 1;
        return count * 2;
    }
};