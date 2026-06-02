class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = size(numbers)-1;

        while (i < j) {
            auto s = numbers[i] + numbers[j];

            if (s > target) --j;
            else if (s < target) ++i;
            else return {i + 1, j + 1};
        }
    }
};
