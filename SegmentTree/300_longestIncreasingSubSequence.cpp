// dp naive
// use segment Tree

struct Node
{
    int sum;
    int maxPrefixSum;

    Node(int sum = -1, int maxPrefixSum = -1) : sum(sum), maxPrefixSum(maxPrefixSum)
    {
    }
};

// function to compare two pairs 
int compare(pair<int, int> p1, pair<int, int> p2) 
{ 
     /* For same values, element with the higher  
        index appear earlier in the sorted array. 
        This is for strictly ifncreasing subsequence. 
        For increasing subsequence, the lower index  
         appears earlier in the sorted array. */
    if (p1.first == p2.first)  
        return p1.second > p2.second; 
      
    // Sorting the array according to their values. 
    return p1.first < p2.first; 
} 

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
    }
};