class Solution {
public:
    int rob(vector<int>& nums) {

        if (size(nums) == 1)return nums[0];
        // same as line rob,, except I'll consider whether I should include others
        vector<int> nums1(nums.begin() +1, nums.end());
        vector<int> nums2(nums.begin(), nums.end()- 1);
        return max(robline(nums1) , robline(nums2));
        
        
    }

    int robline(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for(int num: nums) {
            int temp = max( num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }


        return rob2;
    }

};
