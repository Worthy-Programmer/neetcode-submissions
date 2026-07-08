class Solution {
public:
    vector<int> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        memo = vector<int> (size(s), -1);


        int siz = 0;

        int minS = INT_MAX;
        int maxS = INT_MIN;
        for (auto w: wordDict) {
            siz = size(w);
            if (siz > maxS) maxS = siz;
            if(siz < minS) minS = siz;
        }
        return dfs(0, wordSet, s, minS, maxS);


    }

// Time to include memo
private:
    bool dfs(int i , set<string>& wordDict, string s, int minS, int maxS) {
                auto n = size(s);
        if (i >= n) return true;

        if (memo[i] != -1) return (memo[i] == 1);

        string word = "";
        int wordsize = 0;

        for (int k = i; k< n; k++) {
            word += s[k];
            wordsize++;

            if (wordsize < minS) continue;
            // cout << word<< '\n';

            // if (size)
            if (wordDict.contains(word) && dfs(k + 1, wordDict, s, minS, maxS)) {
                // cout << word<< '\n';
                    
                memo[i] = true;
                return true;
            }  

            if (wordsize > maxS)
            { memo[i] = false; return false;
            }
        }
        return false;
    }
};
