class Solution
{
  public:
    string minWindow(string s, string t)
    {
        string result;

        unordered_map<char, int> m_hash;
        for (int i = 0; i < t.size(); i++)
        {
            if (m_hash.find(t[i]) == m_hash.end())
            {
                m_hash[t[i]] = 1;
            }
            else
            {
                m_hash[t[i]] = m_hash[t[i]] + 1;
            }
        }

        int required = m_hash.size();

        int l, r;
        l = r = 0;
        int minLength = INT_MAX;
        int minLeft = -1;
        int minRight = -1;

        unordered_map<char, int> windowCache;
        int formed = 0;
        while (r < s.size())
        {
            char c = s[r];
            if (windowCache.find(c) == windowCache.end())
            {
                windowCache[c] = 1;
            }
            else
            {
                windowCache[c] = windowCache[c] + 1;
            }

            if (m_hash.find(c) != m_hash.end() && m_hash[c] == windowCache[c])
            {
                formed++;
            }

            while (l <= r && formed == required)
            {
                char left_c = s[l];
                // t << r - l + 1 << endl;
                if (r - l + 1 < minLength)
                {
                    //ut << l << ' ' << r << endl;
                    minLength = r - l + 1;
                    minLeft = l;
                    minRight = r;
                }

                windowCache[left_c] = windowCache[left_c] - 1;
                if (m_hash.find(left_c) != m_hash.end() && windowCache[left_c] < m_hash[left_c])
                    formed--;

                l++;
            }

            r++;
        }

        return minLength == INT_MAX ? "" : s.substr(minLeft, minRight - minLeft + 1);
    }
};