class Solution
{
  public:
    string frequencySort(string s)
    {
        unordered_map<char, int> m1;
        // default max and sort by first
        priority_queue<pair<int, char>> q1;

        for (int i = 0; i < s.length(); i++)
        {
            m1[s[i]]++;
        }

        for (auto it = m1.begin(); it != m1.end(); it++)
        {
            q1.push(make_pair(it->second, it->first));
        }
        string res = "";
        while (q1.size())
        {
            pair<int, char> y1 = q1.top();
            for (int i = 0; i < q1.top().first; i++)
                res += q1.top().second;
            q1.pop();
        }
        return res;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};