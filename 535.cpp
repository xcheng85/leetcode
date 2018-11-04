class Solution
{
  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        while (true)
        {
            string tmp;
            for (int i = 0; i < num_alphas; i++)
            {
                tmp += m_alphas[rand() % 62];
            }
            if (m_cache.find(tmp) == m_cache.end())
            {
                m_cache[tmp] = longUrl;
                return "http://tinyurl.com/" + tmp;
            }
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return m_cache[shortUrl];
    }

  private:
    const string m_alphas = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int num_alphas = 6;
    unordered_map<string, string> m_cache;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));