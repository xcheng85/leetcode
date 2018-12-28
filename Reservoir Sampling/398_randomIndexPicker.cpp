/* Obviously, Prob(the 3rd char is picked) = 1/3;
Prob(the 2nd char is picked) = 1 * 1/2 * 2/3 = 1/3;
Prob(the 1st char is picked) = 1 * 1/2 * 2/3 = 1/3;

So we can say that when we now has n chars and there is still another char in the file, we can pick the other char with prob= 1/(n+1), also keep original char with prob = n/(n+1), 
then we can secure each char is picked with same prob = 1/(n+1), because prob = 1 * 1/2 * 2/3 * ···· * n/(n+1) = 1/(n+1).

 */


class Solution
{
    vector<int> _nums;

  public:
    Solution(vector<int> nums)
    {
        _nums = nums;
    }

    int pick(int target)
    {
        int n = 0, ans = -1;
        for (int i = 0; i < _nums.size(); i++)
        {
            if (_nums[i] != target)
                continue;
            if (n == 0)
            {
                ans = i;
                n++;
                // 1
            }
            else
            {
                // n == 2   1 * 1/2
                // 50% 
                // n = 3   1 * 1/2 * 2 / 3
                n++;
                if (rand() % n == 0)
                {
                    ans = i;
                } // with prob 1/(n+1) to replace the previous index
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */