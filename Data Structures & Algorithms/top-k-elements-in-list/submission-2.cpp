// Using Bucket Sort; Space and Time O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ft;
        for(auto n: nums) ft[n]++; // O(n)

        // Creating buckets - Frequecies range from 1 to n , so we need n+1 length
        vector<vector<int>> buckets(size(nums) + 1); // Space: O(n)

        for (auto &it: ft) {
            buckets[it.second].push_back(it.first); // O(n)
        }

        vector<int> res;
        for (int i = size(nums); i > 1; --i) { // O(k)
            for(auto n: buckets[i]) {
                res.push_back(n);

                if (res.size() >= k) return res;
            }

        }

    }
};
