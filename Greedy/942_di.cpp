// greedy, start with max and min matching D and I

class Solution
{
  public:
    vector<int> diStringMatch(string S)
    {
        int N = S.size();
        int lo = 0, hi = N;
        vector<int> ans(N+1, 0); 
        for (int i = 0; i < N; ++i)
        {
            if (S[i] == 'I')
                ans[i] = lo++;
            else
                ans[i] = hi--;
        }

        ans[N] = lo;
        return ans;
    }
};
