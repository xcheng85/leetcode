class Solution
{
  public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        if (n == 1)
            return 1;

        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);

        for (int i = 1; i < n; i++)
        {
            long tmp = pq.top();
            pq.pop();
            while (!pq.empty() && pq.top() == tmp)
            {
                pq.pop(); // remove the duplicate
            }

            for(auto& prime: primes){
                pq.push(tmp * prime);
            }
        }

        return pq.top();
    }
};