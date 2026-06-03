class Solution {
public:
    int trap(vector<int>& height) {
        // Use 2 pointers 

        int n = size(height);
        int i = 0;
        int j = n - 1;

        int leftMax= height[i];
        int rightMax = height[j];

        int res= 0;

        while (i < j) {

            if (leftMax < rightMax) {
                i++; leftMax = max(leftMax, height[i]);
                res += leftMax - height[i];
            } else {
                j--; rightMax = max(rightMax, height[j]);
                res += rightMax - height[j];
            }
        }

        return res;
    }
};
