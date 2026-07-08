class Solution {
public:
    int numDecodings(string s) {
        int n = size(s);
        vector<int> N (n+ 2);
        N[n] = 1;
        N[n+1] = 1;

        for(int i = n-1; i>=0; i--) {
            cout << s.substr(i,2) << '\n';
            auto z = stoi(s.substr(i, 2));
            if (s[i] != '0') N[i] += N[i+1];
            if (10 <= z && z <= 26) N[i] += N[i+2];
        }

        return N[0];
    }
};
