class Solution {
public:
    vector<vector<int>>cache; 

    int lengthOfLIS(vector<int>& nums) {
        // j ranges from -1 to n-1
        auto n = size(nums);
        cache = vector<vector<int>> (n, vector<int>(n+1, -1));
        return dfs(nums, 0, -1);
    }

private:
    int dfs(vector<int> &nums, int start, int prev) {

        if (start >= size(nums)) return 0;
        // pair<int, int> state = {start, prev};
        if (cache[start][prev+1] != -1 ) return cache[start][prev+1];


        int val = INT_MIN;
        if (prev != -1)val = nums[prev];

        int n1 = 0;

        if (prev == -1 || nums[start] > val) {
            // I can include it now
            n1 = 1 + dfs(nums, start + 1, start);
        }

        int n2 =  dfs(nums, start + 1, prev); // Not including

        auto maxn =  max(n1, n2);
        cache[start][prev+1] = maxn;
        return maxn;
    
    }
};