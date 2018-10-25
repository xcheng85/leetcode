class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;

        string local;
        backtracking(res, n, n, local);

        return res;
    }

    void backtracking(vector<string> &res, int leftBracket, int rightBracket, string &local)
    {
        if (leftBracket == 0 && rightBracket == 0)
        {
            res.push_back(local);
        }
        else
        {
            if (leftBracket == rightBracket)
            {
                local.push_back('(');
                backtracking(res, --leftBracket, rightBracket, local);
                local.pop_back();
            }
            else if (leftBracket < rightBracket)
            {
                if (leftBracket == 0)
                {
                    local.push_back(')');
                    backtracking(res, leftBracket, --rightBracket, local);
                    local.pop_back();
                }
                else
                {
                    local.push_back(')');
                    backtracking(res, leftBracket, --rightBracket, local);
                    local.pop_back();

                    rightBracket++;
                    local.push_back('(');
                    backtracking(res, --leftBracket, rightBracket, local);
                    local.pop_back();
                }
            }
            else
            {
                cout << 'never happen' << endl;
            }
        }
    }
};