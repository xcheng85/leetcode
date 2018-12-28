class Compare
{
  public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second <= rhs.first;
    }
};

class MyCalendar
{
  public:
    // We use a set of pairs with custom comparator to keep the reservations ordered.
    // The comparator judges whether one reservation comes before another reservation.
    // Two reservations are considered equal if neither comes before the other, i.e., they overlap.
    set<pair<int, int>, Compare> s;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        if (s.find(make_pair(start, end)) == s.end())
        {
            // If overlap
            s.insert(make_pair(start, end));
            return true;
        }
        else
        {
            // No overlap
            return false;
        }
    }
};