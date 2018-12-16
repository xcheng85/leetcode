#include <vector>

// restraints: no duplicates
// sum of hours must < 12
// sum of mins must < 60
// num > 10
// hour 8 4 2 1

// 3 -- 0

// min: 32 16 8 4 2 1

// 5 -- 0

class Solution
{
public:
  vector<string> readBinaryWatch(int num)
  {
    vector<string> ans;
    backtracking(num, 10, 0, 0, ans);
    return ans;
  }

private:
  void backtracking(int num_left, int hourmins_left, int hours, int minutes, vector<string> &res)
  {
    if (num_left == 0)
    {
      // key
      if (hours >= 12 || minutes >= 60)
      {
        return;
      }
      string tmp = std::to_string(hours);
      tmp += ":";
      if (minutes < 10)
      {
        tmp += "0";
      }
      tmp += std::to_string(minutes);
      res.push_back(tmp);
    }
    else
    {
      if (hourmins_left < num_left)
        return; // trim

      if (hourmins_left >= 7)
      {
        int delta = pow(2, hourmins_left - 7);
        // take hour
        backtracking(num_left - 1, hourmins_left - 1, hours + delta, minutes, res);
        // ignore hour
        backtracking(num_left, hourmins_left - 1, hours, minutes, res);
      }
      else
      {
        //  cout << num_left << " " << hourmins_left << endl;
        int delta = pow(2, hourmins_left - 1);
        backtracking(num_left - 1, hourmins_left - 1, hours, minutes + delta, res);
        backtracking(num_left, hourmins_left - 1, hours, minutes, res);
      }
    }
  }
};