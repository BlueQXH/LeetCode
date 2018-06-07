class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> m;
        int mid = candies.size()/2;
        for (int &i : candies) {
            if (m.find(i) == m.end())
                m.insert(make_pair(i, 1));
            else
                ++m[i];
        }
        return min(mid, (int)m.size());
    }
};
