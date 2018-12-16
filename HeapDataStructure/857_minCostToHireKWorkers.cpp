/* Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker. */

/**
 * try every worker with unit quality wage/quality and with minimum requirements
 */

#include <vector>

class Solution
{
  public:
    struct Person
    {
        int quality;
        int wage;
        double wagePerQuality;
        Person(int _qual, int _wage)
        {
            qual = _qual;
            wage = _wage;
            wagePerQuality = (double)wage / qual;
        }
    };

    struct comparator
    {
        bool operator()(const Person &a, const Person &b)
        {
            return a.wagePerQuality < b.wagePerQuality;
        }
    };

    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int K)
    {
        int n = wage.size();

        vector<Person> workers;

        //Inserting all the workers in vector
        for (int i = 0; i < n; i++)
        {
            Person p(quality[i], wage[i]);
            workers.push_back(p);
        }

        //Sorting them according in ASC order of Wage/Quality (Lowest cost of 1 unit quality first)
        sort(workers.begin(), workers.end(), comparator());

        //Now we are sure that the first K members of this group will give the best scenario
        //The Kth person's rate will be considered. And it will be multiplied with total quality required till K

        //BUT
        //There might be a case where we can have people later with higher rates(for sure) and lower quality required
        //SO to try that we just remove the top quality person till now and use the rate of the higher guy

        priority_queue<int> pq; //Just Store the "QUALITY REQUIRED" in MAX HEAP

        int totalQuality = 0;
        double minCost = std::numeric_limits<double>::max();

        for (auto worker : workers)
        {
            //This rate will be applicable to all people seen before as well, because it is already sorted by unit wage per quality, 
            // secret is here !!!
            double rate = worker.wagePerQuality;

            totalQuality += worker.qual;
            pq.push(worker.qual);

            if (pq.size() > K)
            {
                totalQuality -= pq.top(); // pop the largest quatity, secret too !!!
                pq.pop();
            }

            if (pq.size() == K)
            {
                minCost = min(minCost, rate * totalQuality);
            }
        }

        return minCost;
    }
};