class Solution {
public:
    bool isAnagram(string s, string t) {
        // Check length first
        if (s.size() != t.size()) return false; 
        return createMap(s) == createMap(t);
    }

    unordered_map<char,int> createMap(string s) {
        unordered_map<char, int> m;
        for (auto c: s) m[c]++;
        return m;
    }
};
