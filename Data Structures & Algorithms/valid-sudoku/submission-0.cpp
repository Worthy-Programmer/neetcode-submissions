class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // We can check all 3 cases by only looping once

        // Using bitmask - A 10 digit binary numbers

        vector<int> row_mask(9);
        vector<int> col_mask(9);
        vector<int> square_mask (9);

        // Initially writing logic only for row and col

        for (int i = 0; i < 9 ; i++) {
            // Row mask index = i
            // Col mask index = j
            for (int j = 0; j< 9; j++) {
                auto s = board[i][j];
                if (s == '.') continue;
                auto n = s - '0';

                auto mask = 1 << n;

                if ( row_mask[i] & mask ) return false;
                row_mask[i] |= mask;

                if (col_mask[j] & mask) return false;
                col_mask[j] |= mask;

                // Square index Each is marked with i // 3, j // 3  
                int sq_index = (i / 3) * 3 + (j / 3); // Or else you can  use (i/ 3) * 3 + (j/3). Note: (i/3) * 3 is not i
                if (square_mask[sq_index] & mask) return false;
                square_mask[sq_index] |= mask;
            }
        }
        return true;
    }
};
