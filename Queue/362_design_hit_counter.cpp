public class HitCounter {
    private int[] times;
    private int[] hits;
    /** Initialize your data structure here. */
    public HitCounter() {
        times = new int[300];
        hits = new int[300];
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        int index = timestamp % 300;
        if (times[index] != timestamp) {
            times[index] = timestamp;
            hits[index] = 1;
        } else {
            hits[index]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < 300; i++) {
            if (timestamp - times[i] < 300) {
                total += hits[i];
            }
        }
        return total;
    }
}

class HitCounter
{
  private:
    queue<pair<int, int>> hits;
    int cnt;

  public:
    /** Initialize your data structure here. */
    HitCounter()
    {
        cnt = 0;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp)
    {
        // maintain the queue to get rid of the outdated hit pair
        while (!hits.empty() && timestamp - hits.front().first >= 300)
        {
            cnt -= hits.front().second;
            hits.pop();
        }
        // count the current hit:
        ++cnt;
        if (!hits.empty() && timestamp == hits.back().first)
            ++(hits.back().second);
        else
            hits.push(make_pair(timestamp, 1));
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp)
    {
        while (!hits.empty() && timestamp - hits.front().first >= 300)
        {
            cnt -= hits.front().second;
            hits.pop();
        }
        return cnt;
    }
};