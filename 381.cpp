class RandomizedCollection
{
  private:
    //unordered_map<int, int> m_hash;
    // unordered_map<int, unordered_set<int>> m_hash; // no rbegin
    unordered_map<int, set<int>> m_hash;
    vector<int> m_array;

  public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (m_hash.find(val) != m_hash.end())
        {
            m_array.push_back(val);
            m_hash[val].insert(m_array.size() - 1);
            return false;
        }

        m_array.push_back(val);
        m_hash[val].insert(m_array.size() - 1);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (m_hash.find(val) == m_hash.end())
            return false;

        int last = m_array.back();
        int toRemoveIdx = *(m_hash[val].rbegin());
        m_hash[last].erase(m_array.size() - 1);
        m_hash[last].insert(toRemoveIdx);
        m_array[toRemoveIdx] = last;
        m_array.pop_back();

        if (m_hash[val].size() > 1)
        {
            m_hash[val].erase(*m_hash[val].rbegin());
        }
        else
        {
            m_hash.erase(val);
        }
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