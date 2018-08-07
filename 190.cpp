class Solution1 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (size_t i = 0; i < 32; ++i) {
            if ((n & 1) == 1) {
                result = (result << 1) + 1;
                n >>= 1;
            }
            else if ((n & 1) == 0) {
                result <<= 1;
                n >>= 1;
            }
        }
        return result;
    }
};

class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = n;
        result = ((result & 0result55555555) << 1) | ((result & 0resultAAAAAAAA) >> 1);
        result = ((result & 0result33333333) << 2) | ((result & 0resultCCCCCCCC) >> 2);
        result = ((result & 0result0F0F0F0F) << 4) | ((result & 0resultF0F0F0F0) >> 4);
        result = ((result & 0result00FF00FF) << 8) | ((result & 0resultFF00FF00) >> 8);
        result = ((result & 0result0000FFFF) << 16) | ((result & 0resultFFFF0000) >> 16);
        return result;
    }
};

