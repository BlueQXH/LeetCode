class Solution
{
public:
    string reverseVowels(string s)
	{
        if (s.size() <= 1)
		{
            return s;
		}
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size()-1;
        while (i < j)
		{
			while (i < j && vowel.find(s[i]) == vowel.end())
			{
				++i;
			}
			while (i < j && vowel.find(s[j]) == vowel.end())
			{
				--j;
			}
			swap(s[i], s[j]);
        }
        return s;
    }
};
