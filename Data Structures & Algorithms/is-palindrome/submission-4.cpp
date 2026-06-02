class Solution {
public:
    bool isPalindrome(string s) {
        // Have 2 pointers: one from first another from second
        int j = s.length() -1;
        int i = 0;

        while (true) {
            while(j > 0 && !isalnum(s[j])) --j;
            while(i < s.length() && !isalnum(s[i])) ++i;

            if (! (j > 0 && i < s.length())) return true;
            if (tolower(s[i]) != tolower(s[j])) return false;
            --j; ++i;
        }
        return true;
        
    }
};
