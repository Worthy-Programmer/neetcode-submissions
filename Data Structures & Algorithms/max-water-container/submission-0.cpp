class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Soln: Start from farthest and find the next biggest of the minimum of 2
        int n = size(heights);
        int i = 0;
        int j = n - 1;

        int max_area = 0;

        while (i < j) {
            auto ar= area(i, j , heights);
            if ( ar > max_area ) max_area = ar;
            int curr_i = i;
            int curr_j = j;

            if (heights[i] < heights[j])
            do ++i; while (heights[i] < heights[curr_i]); // Looping till I get next biggest i;

            else
            do --j; while (heights[j] < heights[curr_j]); // Looping till I get prev biggest j;

            cout << max_area ;
        
        }
        
        return max_area;
    }

    int area(int i, int j, vector<int> & h) {
        return (j-i) * min(h[j], h[i]);
    }
};
