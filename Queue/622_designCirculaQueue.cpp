class MyCircularQueue
{
  private:
    vector<int> m_buffer;
    int m_frontSentinal;
    int m_lastSentinal;
    int m_k;

  public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        m_buffer.resize(k, -1);
        m_frontSentinal = 0;
        m_lastSentinal = 0;
        m_k = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (m_buffer[m_frontSentinal] == -1)
        {
            m_buffer[m_frontSentinal] = value;
            return true;
        }
        else
        {
            int newFrontSentinal = (m_frontSentinal + 1) % m_k;
            if (newFrontSentinal == m_lastSentinal)
                return false;
            else
            {
                m_buffer[newFrontSentinal] = value;
                m_frontSentinal = newFrontSentinal;
                return true;
            }
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (m_buffer[m_lastSentinal] != -1)
        {
            m_buffer[m_lastSentinal] = -1;
            int newLastSentinal = (m_lastSentinal + 1) % m_k;
            if (m_buffer[newLastSentinal] != -1)
            {
                m_lastSentinal = newLastSentinal;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Get the front item from the queue. */
    int Front()
    {
        return m_buffer[m_lastSentinal];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        return m_buffer[m_frontSentinal];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return m_frontSentinal == m_lastSentinal && m_buffer[m_frontSentinal] == -1;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return (m_frontSentinal + 1) % m_k == m_lastSentinal;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */