class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> vec;
        for (const int &i : nums)
        {
            vec.push_back(move(to_string(i)));
        }
        sort(vec.begin(), vec.end(), [](const string& a, const string& b) {return a+b > b+a;});
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
};
