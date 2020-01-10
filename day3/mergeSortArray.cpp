class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0)
        {
            nums1 = nums2;
            return;
        }

        for(auto i = 0; i < m;i++)
        {
            if(nums2[0]<nums1[i])
            {
                nums1[i] = nums1[i]^nums2[0];
                nums2[0] = nums1[i]^nums2[0];
                nums1[i] = nums1[i]^nums2[0];
                resortOrderArray(nums2, n);
            }
        }

        for(auto i = m; i < m+n;i++)
        {
            nums1[i] = nums2[i-m];
        }
    }

    void resortOrderArray(vector<int>& nums, int num)
    {
        for(auto i = 1; i < num; i++)
        {
            if(nums[i-1]>nums[i])
            {
                nums[i-1] = nums[i-1]^nums[i];
                nums[i] = nums[i-1]^nums[i];
                nums[i-1] = nums[i-1]^nums[i];
            }
            else
            {
                break;
            }
        }

        return;
    }
};
