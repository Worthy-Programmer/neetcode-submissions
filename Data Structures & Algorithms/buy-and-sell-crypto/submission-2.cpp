class Solution {
    // Time compexity O(n)
    // Space Compexity O (1) // Just no space complexity
public:
    int maxProfit(vector<int>& prices) {
        // find minStack from left
        // find maxStack from right 

        int n = size(prices);
        int bestBuy = prices[0];

        int bestProfit = 0;

        for (int i =1; i < n; i++) { // If I sell at i
            auto profit =  prices[i] - bestBuy;
            if (profit > bestProfit) bestProfit = profit;

            bestBuy = min(bestBuy, prices[i]);
        }

        return bestProfit;
    }
};
