class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> vec;
        for (const int &i : nums)
        {
            vec.push_back(to_string(i));
        }
        sort(vec.begin(), vec.end(), Comp());
        string ans;
        for (const string &s : vec)
        {
            ans += s;
        }
        if (ans.front() == '0')
        {
            return "0";
        }
        return ans;
    }
private:
    struct Comp
    {
        bool operator()(const string &a, const string &b)
        {
            return a+b > b+a;
        }
    };
};
