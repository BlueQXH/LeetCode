class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int curLength = 0;
        int maxLength = 0;
        
        array<int, 256> position;
        position.fill(-1);
        
        for (int i = 0; i < s.size(); ++i)
        {
            int prevIndex = position[s[i]];
            int d = i - prevIndex;
            if (prevIndex < 0 || curLength < d)
            {
                ++curLength;
            }
            else
            {
                if (maxLength < curLength)
                {
                    maxLength = curLength;
                }
                curLength = d;
            }
            position[s[i]] = i;
        }
        
        //对于长度为1的字符串，前面的循环无法更新maxLength
        if (maxLength < curLength)
        {
            maxLength = curLength;
        }
        return maxLength;
    }
};
