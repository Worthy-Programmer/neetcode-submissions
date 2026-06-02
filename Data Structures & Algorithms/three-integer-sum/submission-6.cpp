class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<int> sorted_nums (nums);
        sort(sorted_nums.begin(), sorted_nums.end());
                    vector<vector<int>> res;

        for (int i = 0; i < size(sorted_nums) -2; i++) {
            if (i > 0 && sorted_nums[i] == sorted_nums[i-1]) continue;
            if (sorted_nums[i] > 0 ) break; // If left is positive, right is positive too
            auto target = -sorted_nums[i];
            int l = i + 1;
            int r = size(sorted_nums) - 1;

            while (l < r) {
                auto sum = sorted_nums[l] + sorted_nums[r];
                if (sum > target) --r;
                else if (sum < target) ++l;
                else {
                    res.push_back({sorted_nums[i], sorted_nums[l], sorted_nums[r]});
                    // do --r; while (l < r && sorted_nums[r] == sorted_nums[r+1]);
                    do ++l; while (l < r && sorted_nums[l] == sorted_nums[l-1]);
                }

            }
        } 

        return res;
    }
};
