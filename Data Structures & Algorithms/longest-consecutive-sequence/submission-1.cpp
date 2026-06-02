class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Empty vector
        if (!nums.size()) return 0;
        unordered_set< int> hashed(nums.begin(), nums.end());

        int max_l = 1;
        int l = 1;
    
        for (auto n: nums) {
            if (hashed.contains(n-1)) continue; // Find start of list

            l = 1;
            while (hashed.contains(++n)) l++; // Loop from that

            if( l > max_l ) max_l = l;
        }

        return max_l;
    }
};
