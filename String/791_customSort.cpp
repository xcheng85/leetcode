struct Comparator
{
  private:
    int *m_cache;

  public:
    Comparator(int *cache)
    {
        m_cache = cache;
    }
    bool operator()(char &l, char &r)
    {
        return m_cache[l - 'a'] < m_cache[r - 'a'];
    }
};

class Solution
{
  private:
    //unordered_map<char, int> m_cache;
    int m_cache[26];

  public:
    string customSortString(string S, string T)
    {
        for (int i = 0; i < S.size(); i++)
        {
            m_cache[S[i] - 'a'] = i;
        }

        sort(T.begin(), T.end(), Comparator(&m_cache[0]));
        return T;
    }
};
