class TwoSum
{
    unordered_map<int, int> map;

  public:
    void add(int number)
    {
        map[number]++;
    }

    bool find(int value)
    {
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            int i = it->first;
            int j = value - i;
            // same number add multiple times
            if ((i == j && it->second > 1) || (i != j && map.find(j) != map.end()))
            {
                return true;
            }
        }
        return false;
    }
};