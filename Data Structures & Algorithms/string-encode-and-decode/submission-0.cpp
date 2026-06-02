class Solution {
// I saw all 3 hints. I am using length# as the escape key ]
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (auto &s: strs) {
            encoded += to_string(s.length()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.length()) {
            int hash_pos = s.find('#', i); // Find index of #
            int len  = stoi(s.substr(i, hash_pos - i)); // substr (Start, Length)
            
            int str_start = hash_pos + 1;
            decoded.push_back(s.substr(str_start, len));
            i  = str_start + len; // Jumping forward
        }

        return decoded;
    }
};
