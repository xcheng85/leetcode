// 214. Shortest Palindrome
// Minimum characters to be added at front to make string palindrome
// lps concept in pattern matching

class Solution
{
  public:
    string shortestPalindrome(string s)
    {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());

        // Get concatenation of string, special character
        // and reverse string
        string concat = s + "$" + revStr;

        vector<int> lps = computeLPSArray(concat); 
  
        // By subtracting last entry of lps vector from 
        // string length, we will get our result 
        int num = (s.size() - lps.back()); 
        
        return revStr.substr(0, num) + s; 
    }

  private:
    vector<int> computeLPSArray(string str)
    {
        int M = str.length();
        vector<int> lps(M);

        int len = 0;
        lps[0] = 0; // lps[0] is always 0

        // the loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < M)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else // (str[i] != str[len])
            {
                // This is tricky. Consider the example.
                // AAACAAAA and i = 7. The idea is similar
                // to search step.
                if (len != 0)
                {
                    len = lps[len - 1];
                    // Also, note that we do not increment
                    // i here
                }
                else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
};