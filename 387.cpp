//此解法假设输入为更广泛的字符，若仅对此题来说只考虑小写字母的话只需要一个大小为26的数组即可
class Solution {
public:
    size_t firstUniqChar(std::string s) {
        std::map<char, size_t> m;
	    std::map<char, size_t> judge;
	    size_t i;
        for (i = 0; i < s.size(); ++i) {
		    if (judge.find(s[i]) == judge.end())
			    judge.insert(std::make_pair(s[i], i));
            if (m.find(s[i]) == m.end())
			    m.insert(std::make_pair(s[i], 1));
		    else
			    ++m[s[i]];
	    }
	    std::vector<size_t> sieve;
        for (auto ite = m.cbegin(); ite != m.cend(); ++ite)
            if (ite->second == 1)
			    sieve.push_back(judge[ite->first]);
	    if (sieve.size()) {
		    std::sort(sieve.begin(), sieve.end());
		    return sieve[0];
	    }
        return -1;
    }
};
