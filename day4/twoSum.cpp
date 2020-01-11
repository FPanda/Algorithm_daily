#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> index2val;
        for(auto i = 0; i < nums.size(); i++)
        {
            auto iter = index2val.find(target-nums[i]);

            if(index2val.end()!=iter)
            {
                vector<int> ret = {iter->second, i};
                return ret;
            }
            
            index2val.insert(make_pair(nums[i],i));
        }

        return vector<int>(0);
    }
};
