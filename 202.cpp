class Solution1 {
public:
    bool isHappy(int n) {
        bool result = true;
        int remainder, sum = n;
     vector<int> nums;
     unordered_set<int> sums;
     while (true) {
         nums.clear();
         while (sum != 0) {
             remainder = sum % 10;
             nums.push_back(remainder);
             sum /= 10;
         }
         for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
             sum  += (*i)*(*i);
         if (sum == 1) {
             result = true;
             break;
         }
         if (!sums.insert(sum).second) {
             result = false;
             break;
            }
     }
     return result;
    }
};

class Solution2 {
public:
    bool isHappy(int n) {
        bool result = true;
        int remainder, sum = n;
     vector<int> nums;
     unordered_set<int> sums;
     while (true) {
         nums.clear();
         while (sum != 0) {
             remainder = sum % 10;
             nums.push_back(remainder);
             sum /= 10;
         }
         for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
             sum  += (*i)*(*i);
         if (sum == 1)
             break;
         if (sum == 4) {
             result = false;
             break;
         }
     }
     return result;
    }
};
