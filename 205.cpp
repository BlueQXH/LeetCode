class Solution {
public:
    bool isOK (string &s1, string &s2) {
	    if (s1.size() != s2.size())
		    return false;
	    unordered_map<char, char> str;
	    for (size_t i = 0; i < s1.size(); ++i)
		    str.insert(make_pair(s1[i], s2[i]));
	    for (size_t j = 0; j < s1.size(); ++j) {
		    if (str.find(s1[j])->second != s2[j])
			    return false;
	    }
	    return true;
        }
    bool isIsomorphic(string s, string t) {
        if (isOK(s, t) && isOK(t, s))
            return true;
        else
            return false;
    }
};
