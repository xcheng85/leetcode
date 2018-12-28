// subproblem memorization
// recursive divide and conquare
// dp  top down

class Solution
{
public:
  vector<int> diffWaysToCompute(string input)
  {
    if (memo.find(input) != memo.end())
      return memo[input];

    vector<int> res;
    for (int i = 0; i < input.size(); i++)
    {
      if (isOperator(input[i]))
      {
        // If character is operator then split and
        // calculate recursively
        vector<int> resPre = diffWaysToCompute(input.substr(0, i));
        vector<int> resSuf = diffWaysToCompute(input.substr(i + 1));

        //  Combine all possible combination
        for (int j = 0; j < resPre.size(); j++)
        {
          for (int k = 0; k < resSuf.size(); k++)
          {
            if (input[i] == '+')
              res.push_back(resPre[j] + resSuf[k]);
            else if (input[i] == '-')
              res.push_back(resPre[j] - resSuf[k]);
            else if (input[i] == '*')
              res.push_back(resPre[j] * resSuf[k]);
          }
        }
      }
    }

      // if input contains only number then save that  
    // into res vector 
    if (res.size() == 0) 
        res.push_back(atoi(input.c_str())); 
  
    // Store in memo so that input string is not  
    // processed repeatedly 
    memo[input] = res; 
    return res;
  }

private:
  bool isOperator(char op)
  {
    return (op == '+' || op == '-' || op == '*');
  }

  unordered_map<string, vector<int>> memo;
};