class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int container = 0;
        int i = 0;
        int j = n-1;

        while(i < j){
            int diff = j - i;
            int store = min(height[i],height[j]);
            int canContain = diff * store;
            container = max(container,canContain);

            if(height[i] <= height[j]) i++;
            else j--;
        }

        return container;
        
    }
};
