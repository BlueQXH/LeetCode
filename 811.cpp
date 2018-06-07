class Solution {  
public:  
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, size_t> m;
        for (string &s : cpdomains) {
            if (s.size() == 0)
                continue;
            size_t pos = s.find(' ');
            int num = stoi(s.substr(0, pos));
            string domain(s.substr(++pos));
            m[domain] += num;
            while ((pos = domain.find('.')) != string::npos) {
                domain = domain.substr(++pos);
                m[domain] += num;
			}
        }
        vector<string> result;
        for (auto &n : m)
            result.push_back(to_string(n.second) + ' ' + n.first);
        return result;
    }  
};
