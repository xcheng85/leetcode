class Solution
{
  public:
    vector<string> generatePossibleNextMoves(string s)
    {
        // backtracking
        vector<string> moves;
        int n = s.length();
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '+' && s[i + 1] == '+')
            {
                s[i] = s[i + 1] = '-';
                moves.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return moves;
    }
};