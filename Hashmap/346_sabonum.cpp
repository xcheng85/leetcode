class Solution
{
  public:
    bool isStrobogrammatic(string num)
    {
        map<char, char> mp{{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
        for (int i = 0; i < num.size(); i++)
        {
            if (mp[num[i]] != num[num.size() - i - 1])
                return false;
        }
        return true;
    }
};