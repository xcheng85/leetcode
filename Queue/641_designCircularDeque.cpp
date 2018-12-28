class MyCircularDeque
{
  private:
    vector<int> m_buffer;
    int m_frontSentinal;
    int m_lastSentinal;
    int m_k;

  public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)
    {
        m_buffer.resize(k, -1);
        m_frontSentinal = 0;
        m_lastSentinal = 0;
        m_k = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
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

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (m_buffer[m_lastSentinal] == -1)
        {
            m_buffer[m_lastSentinal] = value;
            return true;
        }
        else
        {
            int newLastSentinal = (m_lastSentinal - 1 + m_k) % m_k;
            if (newLastSentinal == m_frontSentinal)
                return false;
            else
            {
                m_buffer[newLastSentinal] = value;
                m_lastSentinal = newLastSentinal;
                return true;
            }
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (m_buffer[m_frontSentinal] != -1)
        {
            m_buffer[m_frontSentinal] = -1;
            int newFrontSentinal = (m_frontSentinal - 1 + m_k) % m_k;
            if (m_buffer[newFrontSentinal] != -1)
            {
                m_frontSentinal = newFrontSentinal;
            }
            return true;
        }
        else
            return false;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
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

    /** Get the front item from the deque. */
    int getFront()
    {
        return m_buffer[m_frontSentinal];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        return m_buffer[m_lastSentinal];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return m_frontSentinal == m_lastSentinal && m_buffer[m_frontSentinal] == -1;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return (m_frontSentinal + 1) % m_k == m_lastSentinal;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */