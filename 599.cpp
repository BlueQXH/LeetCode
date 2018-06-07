class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, size_t> m1, m2;
        vector<string> result;
        size_t i;
        for (i = 0; i < list1.size(); ++i)
            m1[list1[i]] = i;
        for (i = 0; i < list2.size(); ++i)
            m2[list2[i]] = i;
        vector<pair<size_t, string>> pos_sum;
        size_t min;
        for (auto ite = m1.begin(); ite != m1.end(); ++ite) {
            auto tmp = m2.find(ite->first);
            if (tmp != m2.end())
                pos_sum.push_back(make_pair(ite->second + tmp->second, ite->first));
        }
        sort(pos_sum.begin(), pos_sum.end());
        vector<pair<size_t, string>>::const_iterator it = pos_sum.cbegin();
        while (it->first == pos_sum.cbegin()->first) {
            result.push_back(it->second);
            ++it;
        }
        return result;
    }
};
