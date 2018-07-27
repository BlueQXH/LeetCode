class Solution {
public:
    bool validPalindrome(string s) {
        size_t i, j, si, sj, count = 0, way = 0;
        for(i = 0, j = s.size()-1; i < j; ++i, --j){
            if(s[i] != s[j]) {
                if(way == 2)
                   return false;
                if(way==1) {
                    ++way;
                    i = si;
                    j = sj;
                    ++j; 
                }
                if(way == 0) {
                    ++way;
                    count = 1;
                    si = i;
                    sj = j;
                    --i;
                }
            }  
        }
        return true;
    }
};
