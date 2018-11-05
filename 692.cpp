class Compare
{
  public:
    bool operator()(pair<string, int> &lhs, pair<string, int> &rhs)
    {
        // min on top 
        return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
    }
};

class Solution
{
  public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> cache;

        for (int i = 0; i < words.size(); i++)
        {
            cache[words[i]]++;
        }

        std::priority_queue<pair<string, int>, std::vector<pair<string, int>>, Compare> q;

        for (unordered_map<string, int>::iterator it = cache.begin(); it != cache.end(); it++)
        {
            q.push(make_pair(it->first, it->second));
            if (q.size() > k)
            {
                q.pop();
            }
        }

        vector<string> ans;

        while (!q.empty())
        {
            ans.push_back(q.top().first);

            q.pop();
        }

        //important
        reverse(ans.begin(), ans.end());

        return ans;
    }
};