class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry = 0, ai, bi, sum;
        for (ai = a.size()-1, bi = b.size()-1; ai >= 0 && bi >= 0; --ai, --bi) {
            sum = (a[ai]-'0')+(b[bi]-'0')+carry;
            result.push_back(sum%2+'0');
            carry = sum/2;
        }
        if (a.size() < b.size()) {
            do {
                sum = (b[bi]-'0')+carry;
                result.push_back(sum%2+'0');
                carry = sum/2;
                --bi;
            } while (bi >= 0);
        }
        else if (a.size() > b.size()) {
            do {
                sum = (a[ai]-'0')+carry;
                result.push_back(sum%2+'0');
                carry = sum/2;
                --ai;
            } while (ai >= 0);
        }
        if (carry == 1)
            result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
