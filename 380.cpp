class RandomizedSet
{
  private:
    unordered_map<int, int> m_hash;
    vector<int> m_array;

  public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m_hash.find(val) != m_hash.end())
            return false;
        m_array.push_back(val);
        m_hash[val] = m_array.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m_hash.find(val) == m_hash.end())
            return false;

        int last = m_array.back();
        m_hash[last] = m_hash[val];
        m_array[m_hash[val]] = last;

        m_array.pop_back();
        m_hash.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int idx = rand() % m_array.size();
        return m_array[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */