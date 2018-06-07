class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> dis_map;
        int result = 0;
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = 0; j < points.size(); ++j)
                ++dis_map[pow(points[i].first-points[j].first, 2) + pow(points[i].second-points[j].second, 2)];
            for (auto ite = dis_map.cbegin(); ite != dis_map.cend(); ++ite)
                result += ite->second * (ite->second - 1);
	        dis_map.clear();
	    }
        return result;
    }
};
