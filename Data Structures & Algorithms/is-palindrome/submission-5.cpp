class Solution {
public:
    bool isPalindrome(string s) {
        // Have 2 pointers: one from first another from second
        int j = s.length() -1;
        int i = 0;

        while (i < j) {
            while(i < j && !isalnum(s[j])) --j;
            while(i < j && !isalnum(s[i])) ++i;
            
            if (tolower(s[i]) != tolower(s[j])) return false;
            --j; ++i;
        }
        return true;
        
    }
};
