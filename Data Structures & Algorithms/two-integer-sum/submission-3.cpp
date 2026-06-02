class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for(int i = 0; i < size(nums); i++) {
            auto o = target - nums[i];
            if (index.contains(o)) {
                return (vector<int>){index[o], i};
            }
            index[nums[i]] = i;
        }
    }
};
