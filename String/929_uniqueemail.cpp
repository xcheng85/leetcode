class Solution
{
  public:
    int numUniqueEmails(vector<string> &emails, unordered_set<string> unique = {})
    {
        for (const auto &email : emails)
        {
            auto pivot = email.find_first_of('@');
            auto name = email.substr(0, pivot), domain = email.substr(pivot);
            name.erase(remove_if(name.begin(), name.end(), [](const auto &c) { return c == '.'; }), name.end());
            unique.insert(name.erase(name.find_first_of('+')) + domain);
        }
        return static_cast<int>(unique.size());
    }
};