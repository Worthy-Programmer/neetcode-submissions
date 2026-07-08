class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP (amount + 1);
        for (int i = 1; i<= amount; i++) {
            int minv = amount+1;
            for (auto c: coins) {
                if (i-c >= 0 && DP[i-c] >=0) {
                    auto v = DP[i-c] + 1;
                    if (v < minv) minv = v;
                }
            } 

            if (minv > amount) minv = -1;
            DP[i] = minv;
        }

        return DP[amount];
    }
};
