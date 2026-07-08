class Solution {
public:
    int rob(vector<int>& nums) {
        auto n = size(nums);

        if (n == 1) return nums[0];
        if (n == 2) {
            if (nums[0] > nums[1]) return nums[0];
            else return nums[1];
        }

        vector<int> M(n + 1);
        M[n-1] = nums[n-1];

        for (int i = n-2; i >= 0; i--) {
            M[i] = max(nums[i] + M[i+2], M[i+1]);
        }

        return M[0];
    }
};
