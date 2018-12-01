class Solution
{
public:
    void filter(string &str)
    {
        string domain = str.substr(str.find('@'));
        string::iterator ite = str.begin();
        while (*ite != '+' && *ite != '@')
        {
            ++ite;
        }
        ite = remove(str.begin(), ite, '.');
        string local = str.substr(0, ite-str.begin());
        str = local + domain;
    }
    
    int numUniqueEmails(vector<string> &emails)
    {
        int ans = 0;
        if (!emails.empty())
        {
            unordered_set<string> email_set;
            for (string &str : emails)
            {
                filter(str);
                email_set.insert(str);
            }
            ans = email_set.size();
        }
        return ans;
    }
};
