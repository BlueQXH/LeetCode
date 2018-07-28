class Solution1 {
public:
    vector<string> readBinaryWatch(int num) {
		//此种解法效率并不高，因为枚举的命中率与num的数值大小有关，但由于一共只有720种情况，因此此法在时间上并没有多大差别
        vector<string> times;
        for (size_t i = 0; i < 12; ++i) {
            bitset<4> h(i);
            for (size_t j = 0; j < 60; ++j) {
                bitset<6> m(j);
                if (h.count() + m.count() == num)
                    times.push_back(to_string(i) + (j < 10? ":0": ":") + to_string(j));
            }
        }
        return times;
    }
};

class Solution2 {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        recursion(times, make_pair(0, 0), num, 0);
        return times;
    }
private:
    vector<int> hour = {1, 2, 4, 8};
    vector<int> minute = {1, 2, 4, 8, 16, 32};
    void recursion (vector<string> &vec, pair<size_t, size_t> time, int num, size_t index) {
        if (num == 0) {
            if (time.second < 10)
                vec.push_back(to_string(time.first) + ":0" + to_string(time.second));
            else
                vec.push_back(to_string(time.first) + ":" + to_string(time.second));
            return;
        }
        for (size_t i = index; i < hour.size()+minute.size(); ++i) {
            if (i < hour.size()) {
                time.first += hour[i];
                if (time.first < 12)
                    recursion(vec, time, num-1, i+1);
                time.first -= hour[i];
            }
            else {
                time.second += minute[i-hour.size()];
                if (time.second < 60)
                    recursion(vec, time, num-1, i+1);
                time.second -= minute[i-hour.size()];
            }
        }
    }
};
