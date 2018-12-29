class Solution
{
  public:
    string largestTimeFromDigits(vector<int> &A)
    {
        int ans = 0;
        bool overflow = true;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (j != i)
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        if (k != i && k != j)
                        {
                            //index sum : 1 + 2 + 3 + 0 total = 6
                            int l = 6 - i - j - k;

                            // For each permutation of A[i], read out the time and
                            // record the largest legal time.
                            int hours = 10 * A[i] + A[j];
                            int mins = 10 * A[k] + A[l];
                            if (hours < 24 && mins < 60)
                            {
                                ans = max(ans, hours * 60 + mins);
                                overflow = false;
                            }
                        }
                    }
                }
            }
        }
        char buffer[50];
        sprintf(buffer, "%02d:%02d", ans / 60, ans % 60);
        return overflow == false ? buffer : "";
    }
};