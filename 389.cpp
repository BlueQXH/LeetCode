class Solution {
public:
    char findTheDifference(string s, string t) {
	    unordered_map<char, size_t> m1, m2;
	    for (size_t i = 0; i < s.size(); ++i) {
		    if (m1.find(s[i]) == m1.end())
			    m1.insert(make_pair(s[i], 1));
		    else
			    ++m1[s[i]];
	    }
	    for (size_t j = 0; j < t.size(); ++j) {
		    if (m2.find(t[j]) == m2.end())
			    m2.insert(make_pair(t[j], 1));
		    else
			    ++m2[t[j]];
	    }
	    for (auto ite = m2.cbegin(); ite != m2.cend(); ++ite)
		    if (m1.find(ite->first) == m1.end() || m1[ite->first] != ite->second)
			    return ite->first;
	    char c;
	    return c;
    }
};
