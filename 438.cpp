class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> p_map;
        for (char &ch : p) {
            if (p_map.find(ch) == p_map.end())
                p_map.insert(make_pair(ch, 1));
            else
                ++p_map[ch];
        }
        vector<int> result;
        int left = 0, right = 0, cnt = p.size();
        while (right < s.size()) {
            --p_map[s[right]];
            if(p_map[s[right]] >= 0)
                --cnt;
            if(right - left == (p.size() - 1)) {
                if(cnt == 0)
                    result.push_back(left);
                if(p_map[s[left]] >= 0)
                    ++cnt;
                ++p_map[s[left]];
                ++left;
            } 
            ++right;
        }
        return result;
    }
};
