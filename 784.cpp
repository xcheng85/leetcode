class Solution
{
    // dfs
    void backtrack(string &s, int i, vector<string> &res)
    {
        if (i == s.size())
        {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i]))
        {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }

  public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};


// bfs use queue
class Solution {
    public List<String> letterCasePermutation(String S) {
        if (S == null) {
            return new LinkedList<>();
        }
        Queue<String> queue = new LinkedList<>();
        queue.offer(S);
        
        for (int i = 0; i < S.length(); i++) {
            if (Character.isDigit(S.charAt(i))) continue;            
            int size = queue.size();
            for (int j = 0; j < size; j++) {
                String cur = queue.poll();
                char[] chs = cur.toCharArray();
                
                chs[i] = Character.toUpperCase(chs[i]);
                queue.offer(String.valueOf(chs));
                
                chs[i] = Character.toLowerCase(chs[i]);
                queue.offer(String.valueOf(chs));
            }
        }
        
        return new LinkedList<>(queue);
    }
}