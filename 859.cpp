class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() < 2)
            return false;
        vector<size_t> diff;
        for (size_t i = 0; i < A.size(); ++i)
            if (A[i] != B[i])
                diff.push_back(i);
        if (diff.size() == 0) {
            for (size_t j = 0; j < A.size()/2; ++j)
                if (A[j] != A[A.size()/2+j])
                    return false;
            return true;
        }
        else if (diff.size() == 2) {
            swap(A[diff[0]], A[diff[1]]);
            return A == B;
        }
        else
            return false;
    }
};
