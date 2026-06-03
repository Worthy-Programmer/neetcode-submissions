class Solution {
public:
    bool isValid(string s) {

        unordered_set<char> forward_brackets = {'(', '[', '{'};
        unordered_map<char, char> brackets= {{')', '('}, {']', '['}, {'}', '{'}};


        stack<char> st;
        for (auto c: s) {
            if (forward_brackets.contains(c)) {
                st.push(c);
            } else if (brackets.contains(c)) {
                if (st.empty()) return false;
                if (st.top() != brackets[c] ) return false;
                st.pop();
            }
        }

        return st.empty();

    }
};
