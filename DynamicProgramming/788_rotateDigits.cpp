/* 788. Rotated Digits */
// 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate

// bottom-up

class Solution
{
  public:
    int rotatedDigits(int N)
    {
        char[] A = String.valueOf(N).toCharArray();
        int K = A.length;

        int[][][] memo = new int[K + 1][2][2];
        memo[K][0][1] = memo[K][1][1] = 1;
    }
};