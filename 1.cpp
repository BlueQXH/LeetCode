class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> element(2);
        int n=nums.size();
        int i;
        for(i=0;i<n;++i)m[nums[i]]=i;
        for(i=0;i<n;++i)
        {
            int secnum=target-nums[i];
            if(m.count(secnum) && m[secnum]!=i)
            {
                element[0]=i;
                element[1]=m[secnum];
                break;  
            }
        }
        return element;
    }
};
