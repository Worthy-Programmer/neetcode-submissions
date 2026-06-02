// Using Prefix Suffix solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Two - pass solution
        vector<int> prefix(size(nums), 1);
        vector<int> suffix(size(nums) , 1);

        for (size_t i =1; i < size(nums); i++ ) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (auto i = ssize(nums) - 2; i >= 0; --i) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        vector<int> res(size(nums));
        for (size_t i = 0; i < size(nums); i++) {
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};
