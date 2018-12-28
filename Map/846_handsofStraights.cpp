hand = [1,2,3,6,2,3,4,7,8], W = 3

1: 1
2: 2
3: 2 
4: 1
6: 1
7: 1
8: 1

class Solution
{
  public:
    bool isNStraightHand(vector<int> &hand, int W)
    {
        map<int, int> c;
        for (int i : hand)
            c[i]++;

        for (auto it : c)
            if (c[it.first] > 0)
                for (int i = W - 1; i >= 0; --i)
                    if ((c[it.first + i] -= c[it.first]) < 0)
                        return false;
        return true;
    }
};