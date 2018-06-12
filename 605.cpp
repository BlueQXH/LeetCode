class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;
        if (flowerbed.size() < (n>>1))
            return false;
        size_t i = 0;
        while (i < flowerbed.size()) {
            if (flowerbed[i] == 0) {
                if (i+1 >= flowerbed.size()) {
                    flowerbed[i] = 1;
                    --n;
                    break;
                }
                else {
                    if (flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        i += 2;
                        --n;
                    }
                    else
                        ++i;
                }
            }
            else
                i += 2;
        }
        if (n > 0)
            return false;
        return true;
    }
};
