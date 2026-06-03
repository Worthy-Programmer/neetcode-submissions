class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // find minStack from left
        // find maxStack from right 

        int n = size(prices);
        vector<int> bestbuy(n, prices[0]);
        vector<int> bestsell(n, prices[n-1]);

        
        for (int i = 1; i < n; i++) {
            if (bestbuy[i-1] > prices[i]) bestbuy[i] = prices[i];
            else bestbuy[i] = bestbuy[i-1];
        }

        for (int i = n-2; i >=0; i--) {
            if (bestsell[i+1] < prices[i]) bestsell[i] = prices[i];
            else bestsell[i] = bestsell[i+1];
        }

        int mp = 0;
        for (int i = 0; i < n; i++) {
            mp = max(mp, bestsell[i] - bestbuy[i]);
        }

        return mp;
    }
};
