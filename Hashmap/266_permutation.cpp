class Solution
{
  public:
    bool canPermutePalindrome(string s)
    {
        unordered_map<char, int> m;
        for (auto &a : s)
            m[a]++;
        int countOne = 0;
        for (auto &x : m)
            if (x.second % 2 != 0)
                countOne++;
        return countOne <= 1 ? true : false;
    }
};