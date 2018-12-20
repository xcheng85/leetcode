
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

// 1,

// 1*2, 2 *2, 2*3, 2*4, 2*5

// 1*3, 2*3, 3*3 3*4

// 1*5, 2*5 3*5

class Solution
{
  public:
    int nthUglyNumber(int n)
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

            pq.push(tmp * 2);
            pq.push(tmp * 3);
            pq.push(tmp * 5);
        }

        return pq.top();
    }
};