struct Comparator
{
  public:
    bool operator()(const string &s1, const string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();

        int i = 0;
        while (s1[i] != ' ')
        {
            ++i;
        }
        int j = 0;
        while (s2[j] != ' ')
        {
            ++j;
        }

        string id1 = s1.substr(0, i);
        string id2 = s2.substr(0, j);

        ++i;
        ++j;
        while (i < n1 && j < n2)
        {
            if (s1[i] != s2[j])
            {
                return s1[i] < s2[j];
            }
            ++i;
            ++j;
        }

        if (i != 0)
        {
            return false;
        }
        if (j != 0)
        {
            return true;
        }

        // other part exaclty matched
        return id1 < id2;
    }
};

class Solution
{
  private:
    bool isLetterLog(string &str)
    {
        stringstream ss(str);
        string id, word;
        ss >> id >> word;
        return isalpha(word[0]);
    }

  public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> letters;
        vector<string> digits;
        for (auto &s : logs)
        {
            if (isLetterLog(s))
            {
                letters.push_back(s);
            }
            else
            {
                digits.push_back(s);
            }
        }
        sort(letters.begin(), letters.end(), Comparator());

        vector<string> res;
        for (auto &s : letters)
        {
            res.push_back(s);
        }
        for (auto &s : digits)
        {
            res.push_back(s);
        }
        return res;
    }
};