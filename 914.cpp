class Solution {
public:
     bool hasGroupsSizeX(vector<int>& deck) {
    // Simple function to return the gcd
    auto gcd_fct = [] (int a, int b) -> int {
        while (a != b) {
          if (a > b) { 
            a -= b; 
          } else { 
            b -= a; 
          }
        }
        return a;
      };

    // Count the occurances of each number
    std::unordered_map<int, int> freqs;
    for (auto num : deck) {
      ++freqs[num];
    }
   
    // The GCD of all frequencies needs to be more than 2 to be true
    auto it = freqs.begin();
    int divisor = it->second;
    while (++it != freqs.end() && 1 < (divisor = gcd_fct(divisor, it->second)))
      ;
    return (1 < divisor);
  }
};