class Solution {
public:
    using FreqTable = vector<int>;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (auto &s: strs) {
            auto ft = createFreqTable(s);
            m[vectorToString(ft)].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &it: m) {
            res.push_back(it.second);
        }
        
        return res;
    }

    string vectorToString(vector<int> &v) {
        string s;
        for (auto i: v) s+= to_string(i) + ',';
        return s;
    }
    FreqTable createFreqTable(string s) {
        FreqTable fq(26, 0);
        for (auto c: s) fq[c - 'a'] ++;
        return fq;
    }
};
