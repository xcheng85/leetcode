class Solution
{
  public:
    string complexNumberMultiply(string a, string b)
    {
        pair<int, int> av = parse(a);
        pair<int, int> bv = parse(b);
        int ra = av.first * bv.first - av.second * bv.second;
        int rb = av.first * bv.second + av.second * bv.first;
        return to_string(ra) + "+" + to_string(rb) + "i";
    }

    pair<int, int> parse(const string &a)
    {
        int plus = find(a.begin(), a.end(), '+') - a.begin();
        int i = find(a.begin(), a.end(), 'i') - a.begin();
        int ra = stoi(a.substr(0, plus));
        int rb = stoi(a.substr(plus + 1, i - plus));
        return {ra, rb};
    }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};

string complexNumberMultiply(string a, string b) {
    char t[200];
    int m, n, p, q;
    sscanf(a.c_str(), "%d+%di", &m, &n);
    sscanf(b.c_str(), "%d+%di", &p, &q);
    sprintf(t, "%d+%di", (m*p-n*q), (n*p+m*q));
    string ans = t;
    return ans;
}