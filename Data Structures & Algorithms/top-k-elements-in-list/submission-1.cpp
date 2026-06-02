// O(nlogk) solution. Create a frequency table and adding everything to a minheap of size k.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create freqTable
        unordered_map<int, int> ft;
        for (auto n: nums) ft[n]++;


        // Using
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq; // min heap

        // We use min heap because, we can remove the minimum (top) and just keep the top k

        for (auto &e: ft) {
            pq.push({e.second, e.first}); // {Freq, Char}

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;

        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
