class Solution {
public:
      string mostCommonWord(string p, vector<string>& banned) {
          
        unordered_set<string> ban(banned.begin(), banned.end());
          
        unordered_map<string, int> count;
          
        // turn charactor to lowercase
        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
          
        istringstream iss(p);
        string w;
          
        pair<string, int> res ("", 0);
          
        // use stream to do split
        while (iss >> w)
            if (ban.find(w) == ban.end() && ++count[w] > res.second)
                res = make_pair(w, count[w]);
          
        return res.first;
    }
};