class Solution
{
  public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        // 
        sort(deck.begin(), deck.end(), std::greater<int>());
        //sort(deck.rbegin(), deck.rend());
        deque<int> d;
        d.push_back(deck[0]); // max
        for (int i = 1; i < deck.size(); i++)
        {
            // everystep is reverse . 
            // from end to start
            // pop back to replace pop front
           // [13, 17] --- > [11, 17, 13]; 
            d.push_front(d.back());
            d.pop_back();
            d.push_front(deck[i]);
        }
        vector<int> res(d.begin(), d.end());
        return res;
    }
};