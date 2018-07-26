class Solution1 {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, size_t> m1;
        unordered_map<char, char> m2 = {{'L', 'R'}, {'U', 'D'}, {'R', 'L'}, {'D', 'U'}};
        for (char &ch : moves)
            ++m1[ch];
        for (auto ite = m1.begin(); ite != m1.end(); ++ite) {
            if (ite->second != m1[m2[ite->first]])
                return false;
        }
        return true;
    }
};

class Solution2 {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char &ch : moves) {
            if (ch == 'U') ++x;
            else if (ch == 'D') --x;
            else if (ch == 'L') ++y;
            else if (ch == 'R') --y;
        }
        return (x == 0 && y == 0) ? true : false;
    }
};
