class Solution
{
  public:
    // needle is pattern 
    int strStr(string haystack, string needle)
    {
        int m = haystack.length(), n = needle.length();
        // empty pattern, ask interviewer
        if (!n)
        {
            return 0;
        }
        // preprocessing to get lps (longgest prefix string also to be suffix)
        vector<int> lps = kmpProcess(needle);

        // linear matching process
        for (int i = 0, j = 0; i < m;)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == n)
            {   
                // pattern found , first index 
                return i - j;
            }
            // https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
            if ((i < m) && (haystack[i] != needle[j]))
            {
                if (j > 0)
                {
                    j = lps[j - 1]; // revert one back and compare again
                }
                else
                {
                    i++; // non is match, advance i
                }
            }
        }
        return -1;
    }

  private:
    vector<int> kmpProcess(string &needle)
    {
        int n = needle.length();
        vector<int> lps(n, 0);
        // len is previous lps (i-1 step)
        for (int i = 1, len = 0; i < n;)
        {
            if (needle[i] == needle[len]) // AAA
            {
                lps[i++] = ++len;
            }
            else if (len) // len > 0 && AAB
            {
                len = lps[len - 1];
            }
            else // AB
            {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};