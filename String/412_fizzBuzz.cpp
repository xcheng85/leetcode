// if else is slow than write into memory

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret_vec(n);
        for(int i=1; i<=n; ++i)
        {
            if(0 == i%3)
            {
                ret_vec[i-1] += "Fizz";
            }
            if(0 == i%5)
            {
                ret_vec[i-1] += "Buzz";
            }
            if(ret_vec[i-1].empty())
            {
                ret_vec[i-1] += to_string(i);
            }
        }
        return ret_vec;
    }
};

//

class Solution
{
  public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res(n);
        for (int i = 1; i <= n; i++)
        {
            res[i - 1] = to_string(i);
        }
        for (int i = 2; i < n; i += 3)
        {
            res[i] = "Fizz";
        }
        for (int i = 4; i < n; i += 5)
        {
            res[i] = "Buzz";
        }
        for (int i = 14; i < n; i += 15)
        {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};