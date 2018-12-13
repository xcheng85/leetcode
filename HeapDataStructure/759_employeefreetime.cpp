/* Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite. \


schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]

*/
/*      t = 3    t = 4     t = 5                                             t = 7                                size = 1 exit
e1   pop
e2            pop
e3                      pop
                        top become e1 start time is 6 free time is 5,6

e1                                                                        pop
                                                                          top become e4 is 9 [7,9]

e4 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <vector>

class Compare
{
  public:
    bool operator()(Interval &lhs, Interval &rhs)
    {
        // minimal on top
        return (lhs.start > rhs.start) || (lhs.start == rhs.start && lhs.end > rhs.end);
    }
};

class Solution
{
  public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> &schedule)
    {
        vector<Interval> ans;
        priority_queue<Interval, vector<Interval>, Compare> pq;
        int minEndTime = INT_MAX;
        int maxEndTime = INT_MIN;
        for (const auto &s : schedule)
        {
            for (const auto &i : s)
            {
                pq.push(i);
                minEndTime = min(minEndTime, i.end);
                maxEndTime = max(maxEndTime, i.end);
            }
        }

        Interval current(INT_MAX, INT_MIN);
        int t = minEndTime;
        while (t < maxEndTime)
        {
            Interval tmp = pq.top();

            int maxEnd = tmp.end;
            while (tmp.end <= t)
            {
                pq.pop();
                maxEnd = max(maxEnd, tmp.end);
                tmp = pq.top();
            }
            // secret
            if (tmp.start > t)
            {
                current.start = maxEnd;
                current.end = tmp.start;

                ans.push_back(current);
                current.start = INT_MAX;
                current.end = INT_MIN;
            }

            if (pq.size() < 1)
            {
                return ans;
            }

            t = pq.top().end;
        }
        return ans;
    }
};