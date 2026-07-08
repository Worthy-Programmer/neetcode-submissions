class Solution {
public:
    // Basically fibonacci series

    int climbStairs(int n) {
        vector<int> F(n+1);
        if (n <= 1) return 1;

        F[0] = 1; F[1] =1;

        for(int i = 2; i <= n; i++) {
            F[i] = F[i-1] + F[i-2];
        }

        return F[n];

    }
};
