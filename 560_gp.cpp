// 1. prefix sume
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int result = 0;
        int n = nums.size();

        vector<int> preSum(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (preSum[j] - preSum[i] == k)
                    result++;
            }
        }

        return result;
    }
};

//2.
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> cache; // sum, numeof occurance
        int n = nums.size();
        int sum = 0;
        int result = 0;

        // key
        cache[0] = 1; // self , k + 0 = k
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            // is sum - k  not k - sum
            if (cache.find(sum - k) != cache.end())
            {
                result += cache[sum - k];
            }

            cache[sum] = cache[sum] + 1;
        }

        return result;
    }
};

