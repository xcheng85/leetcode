/* 470. Implement Rand10() Using Rand7() */
// Reject Sampling: The main idea is when you generate a number in the desired range, output that number immediately. If the number is out of the desired range, reject it and re-sample again.
// As each number in the desired range has the same probability of being chosen, a uniform distribution is produced.
class Solution
{
  public:
    int rand10()
    {
        int row, col, idx;
        do
        {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};