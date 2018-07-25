class Solution {
public:
    int compress(vector<char>& chars) {
        size_t i = 0, j = 0;
        while (j < chars.size()) {
            if (j == chars.size() - 1 || chars[j] != chars[j + 1])
                chars[i++] = chars[j++];
            else {
                chars[i++] = chars[j];
                int k = j;
                while (j < chars.size() && chars[j] == chars[k])
                    ++j;
                string s = to_string(j - k);
                cout << s << " " << i << " " << j << " " << k << endl;
                for (char c : s)
                    chars[i++] = c;
            }
        }
        return i;
    }
};
