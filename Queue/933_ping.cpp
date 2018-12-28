class RecentCounter
{

  private:
    queue<int> m_q;
    int m_delta;

  public:
    RecentCounter() : m_delta(3000)
    {
    }

    int ping(int t)
    {
        if (m_q.size() == 0)
        {
            m_q.push(t);
        }
        else
        {
            while (m_q.size() > 0 &&
                   m_q.front() < t - 3000)
            {
                m_q.pop();
            }
            m_q.push(t);
        }
        return m_q.size();
    }
};