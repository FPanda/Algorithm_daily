class Solution {
public:  
    void rotate(vector<int>& nums, int k) {
        int num = nums.size();

        if(num == 0)
        {
            return;
        }

        if(k%num==0)
        {
            return;
        }
        int move = k%num;

        reverse(nums, 0, num-1);
        reverse(nums,0,move-1);
        reverse(nums,move,num-1);

        return;
    }

    void reverse(vector<int>& nums, int start, int end)
    {
        int length = end - start + 1;
        for(auto i = 0; i < (length >> 1);i++)
        {
            int temp = nums[start+i];
            nums[start+i] = nums[end-i];
            nums[end-i] = temp;
        }

        return;
    }
};
