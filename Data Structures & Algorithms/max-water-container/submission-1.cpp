class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Soln: Start from farthest and find the next biggest of the minimum of 2
        int n = size(heights);
        int i = 0;
        int j = n - 1;

        int max_area = 0;

        while (i < j) {
            int hi = heights[i];
            int hj = heights[j];
            auto ar= (j - i) * min(hi, hj);
            if ( ar > max_area ) max_area = ar;

            if (hi < hj)
            do ++i; while (heights[i] < hi); // Looping till I get next biggest i;

            else
            do --j; while (heights[j] < hj); // Looping till I get prev biggest j;

            // cout << max_area ;
        
        }
        
        return max_area;
    }

    int area(int i, int j, vector<int> & h) {
        return (j-i) * min(h[j], h[i]);
    }
};
