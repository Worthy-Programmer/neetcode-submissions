class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto n = size(nums);
        if (n==1) return nums[0];

        int maxm = numeric_limits<int>::min();



        vector<vector<int>> M (n, vector<int>(n));

        // for(int i= 0 ; i<n; i++) M[i][i] = nums[i];

        for (int i =0; i < n ; i ++) {
            for (int j = i ; j < n; j++) {
                if (i == j) M[i][j] = nums[i];
                else M[i][j] = M[i][j-1] * nums[j];

                if (M[i][j] >=  maxm) maxm = M[i][j];
            }
        }

        return maxm;
    }
};
