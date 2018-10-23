// # 1 brutal force
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.size() == 0)
            return false;

        unordered_set<int> mySet;

        return helper(s, 0, mySet, wordDict);
    }

    bool helper(string s, int index, unordered_set<int> cache, vector<string> &wordDict)
    {
        if (index == s.size())
            return true;

        for (int i = index + 1; i <= s.size(); i++)
        {
            if (cache.find(i) != cache.end())
                continue;
            if (find(wordDict.begin(), wordDict.end(), s.substring(index, i)) != wordDict.end())
            {
                if (helper(s, i, cache, wordDict))
                    return true;
                cache.insertt(i);
            }
        }

        return false;
    }
};

/* SOLUTION 2: dfs
    use a set to record the substring (i, s.length) that is not breakable
    start from the front, try to see if the substring (0,i) is in the dict,
    if so, recursively check if there is a way to break (i, s.length)
    
    
public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        if(s.length() == 0) return false;
        Set<Integer> set = new HashSet<Integer>();
        return helper(s, 0, set, wordDict);
    }
    
    private boolean helper(String s, int index, Set<Integer> set, Set<String> dict){
        if(index == s.length()) return true;
        for(int i = index + 1; i <= s.length(); i++){
            if(set.contains(i)) continue;
            if(dict.contains(s.substring(index, i))){
                 if (helper(s, i, set, dict)) return true;
                 set.add(i);
            }
        }
        return false;
    }
}



  public boolean wordBreak(String s, Set<String> wordDict) {
        if(s.length() == 0) return false;
        boolean[] breakable = new boolean[s.length() + 1];
        breakable[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(breakable[j] && wordDict.contains(s.substring(j, i))){
                    breakable[i] = true;
                    break;
                }
            }
        }
        //for(boolean b : breakable) System.out.print(b + ", ");
        return breakable[s.length()];
    }

    */

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> mySet(wordDict.begin(), wordDict.end()); 
        int n = s.size(); 
        vector<bool> breakable(n+1, false); 
        breakable[0] = true; 

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(breakable[j] && mySet.find(s.substr(j, i - j))!=mySet.end()){
                    breakable[i] = true;
                    break;
                }
            }
        }

         return breakable[s.size()];
    }
};


//3 bfs

public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        int index = 0;
        Queue<String> queue = new LinkedList<String>();
        queue.offer(s);
        Set<String> visited = new HashSet<String>();
        while(!queue.isEmpty()){
            String candidate = queue.poll();
            if(wordDict.contains(candidate)) return true;
            for(int i = 0; i < candidate.length(); i++){
                String chop = candidate.substring(0,i);
                String next = candidate.substring(i, candidate.length());
                if(!visited.contains(next) && wordDict.contains(chop)){
                    next = candidate.substring(i, candidate.length());
                    queue.offer(next);
                    visited.add(next);
                }
            }
        }
        return false;
    }
}


class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
       int index = 0;
       queue<string> bfs; 
       bfs.push(s); 

       set<string> visited; 
       while(!bfs.empty()){
           string top = bfs.front(); 
           bfs.pop(); 

           if(std::find(wordDict.begin(), wordDict.end(), top) != wordDict.end()){
               return true; 
           }

           for(int i = 0; i < top.size(); i++){
               string left = top.substr(0, i);
               string right = top.substr(i, top.size() - i); 

               if() 

           }
       }
    }
};