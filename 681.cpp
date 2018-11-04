class Solution
{
  public:
    string nextClosestTime(string time)
    {
        // convert to mins
        int cur = 60 * stoi(time.substr(0, 2)) + stoi(time.substr(3, 2));
        unordered_set<int> cache;

        for (int i = 0; i < time.size(); i++)
        {
            if (time[i] != ':')
            {
                cache.insert(time[i] - '0');
            }
        }

        //beginning of simulation
        while (true)
        {
            cur = (cur + 1) % (24 * 60);
            int hour = cur / 60;
            int min = cur % 60;
            vector<int> digits{hour / 10, hour % 10, min / 10, min % 10};
            bool isLegit = true;
            for (int i = 0; i < digits.size(); i++)
            {
                if (cache.find(digits[i]) == cache.end())
                {
                    isLegit = false;
                    break;
                }
            }

            if (isLegit)
            {
                return to_string(digits[0]) + to_string(digits[1]) + ":" + to_string(digits[2]) + to_string(digits[3]);
            }
        }
    }
};
