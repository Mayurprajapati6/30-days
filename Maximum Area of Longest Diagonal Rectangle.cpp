class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        int maxArea = 0;

        for(auto &rect: dimensions) {
            int length = rect[0];
            int width  = rect[1];
            double diagonal = sqrt(length * length + width * width);
            int area = length * width;

            if(diagonal > maxDiagonal || (diagonal == maxDiagonal && area > maxArea)) {
                maxArea = area;
                maxDiagonal = diagonal;
            }
        }
        return maxArea;
    }
};
