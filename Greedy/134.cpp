// bus stop gas and cost

// use two pointer to emulate queue

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if (gas.size() == 1)
        {
            return gas[0] >= cost[0] ? 0 : -1;
        }

        int n = gas.size();

        int start = 0;
        int end = 1;

        int leftover = gas[0] - cost[0];

        // be carefaul is != not  < 
        while (start != end || leftover < 0)
        {
            while (start != end && leftover < 0)
            {
                //cout << leftover << endl;
                // Remove starting petrol pump. Change start
                leftover -= gas[start] - cost[start];
                start = (start + 1) % n;

                if (start == 0) // all the result has been considered
                    return -1;
            }

            // Add a petrol pump to current tour
            leftover += gas[end] - cost[end];
            end = (end + 1) % n;
        }
        return start;
    }
};