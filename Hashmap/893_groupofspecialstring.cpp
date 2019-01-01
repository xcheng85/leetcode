class Solution
{
  public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        unordered_set<string> cache;
        for (auto &s : A)
        {
            int count[52];
            memset(count, 0, sizeof(count));
            for (int i = 0; i < s.size(); ++i)
                count[s[i] - 'a' + 26 * (i % 2)]++;
            string key = "";
            for (int i = 0; i < 52; i++)
                key += to_string(count[i]);
            cache.insert(key);
        }
        return cache.size();
    }
};
