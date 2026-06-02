class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        int zero_len = 0;
        for (auto &n: nums) {
            if (n == 0) zero_len++;
            else mul *= n;
        };


        vector<int> res;
        for (auto &n: nums) {
            if (n!=0 && zero_len == 0)  res.push_back(mul / n);
            else if (n == 0 && zero_len == 1) res.push_back(mul);
            else if (zero_len > 1 || (n!= 0 and zero_len > 0)) res.push_back(0);
        }

        return res;
    }
};
