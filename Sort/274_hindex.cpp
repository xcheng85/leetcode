class Solution
{
  public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);
        int count = 0;
        for (auto c : citations)
        {
            if (c >= n)
                buckets[n]++;
            else
                buckets[c]++;
        }

        for (int i = n; i >= 0; i--)
        {
            count += buckets[i];
            if (count >= i)
            {
                return i;
            }
        }

        return 0;
    }
};
