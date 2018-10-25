/* Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false. */

class Solution
{
  public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) { return a.start < b.start; });
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto interval : intervals)
        {
            if (!min_heap.empty() && min_heap.top() <= interval.start)
                min_heap.pop();
            min_heap.push(interval.end);
        }

        return min_heap.size();
    }
};


int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> starts, ends;
    for (auto i : intervals) {
        starts.push_back(i.start);
        ends.push_back(i.end);
    }
    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));
    int e = 0, rooms = 0, available = 0;
    for (int start : starts) {
        while (ends[e] <= start) {
            ++e;
            ++available;
        }
        available ? --available : ++rooms;
    }
    return rooms;
}