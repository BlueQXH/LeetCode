class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if (seats.size() == 2)
            return 1;
        int result = 1, cnt = 0;
        size_t i = 0, j = seats.size()-1;
        for (cnt = 0; seats[i] == 0 && i < seats.size(); ++i)
            ++cnt;
        result = max(result, cnt);
        for (cnt = 0; seats[j] == 0 && j >= 0; --j)
            ++cnt;
        result = max(result, cnt);
        cnt = 0;
        for (cnt = 0; i <= j; ++i) {
            if (seats[i] == 0)
                ++cnt;
            else {
                cnt = (cnt%2 == 0) ? cnt/2 : cnt/2+1;
                result = max(result, cnt);
                cnt = 0;
            }
        }
        return result;
    }
};
