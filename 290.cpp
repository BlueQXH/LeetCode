class Solution1 {
public:
    bool wordPattern (string &pattern, string str) {
	    istringstream read(str);
	    vector<string> vec_str;
	    string word;
	    while (read >> word)
		vec_str.push_back(word);
	    if (pattern.size() != vec_str.size())
		    return false;
	    unordered_map<char, string> match;
	    size_t i;
	    for (i = 0; i < pattern.size(); ++i) {
		    if (match.find(pattern[i]) == match.end()) {
			    for (auto j = match.cbegin(); j != match.cend(); ++j)
				    if ((*j).second == vec_str[i])
					    return false;
			    match.insert(make_pair(pattern[i], vec_str[i]));
		    }
		    else
			    if (match[pattern[i]] != vec_str[i])
				    return false; 
	    }
	    return true;
    }
};

class Solution2 {
public:
    bool wordPattern (string &pattern, string str) {
	    istringstream read(str);
	    vector<string> vec_str;
	    string word;
	    while (read >> word)
		vec_str.push_back(word);
	    if (pattern.size() != vec_str.size())
		    return false;
	    unordered_map<char, string> match1;
        unordered_map<string, char> match2;
        bool isPattern = true;
	    for (size_t i = 0; i < pattern.size(); ++i) {
		    if(match1.find(pattern[i]) != match1.end() && match1[pattern[i]] != vec_str[i]) {
                isPattern = false;
                break;
            }
            else if (match1.find(pattern[i]) == match1.end())
                match1.insert(make_pair(pattern[i], vec_str[i]));
            if (match2.find(vec_str[i]) != match2.end() && match2[vec_str[i]] != pattern[i]) {
                isPattern = false;
                break;
            }
            else if (match2.find(vec_str[i]) == match2.end())
                match2.insert(make_pair(vec_str[i], pattern[i]));
	    }
	    return isPattern;
    }
};
